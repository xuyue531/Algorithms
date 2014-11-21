package lru;

import java.util.Map;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantReadWriteLock;

/**
 * Ĭ��ʵ��
 * @author
 *
 * @param <K>
 * @param <V>
 */
public abstract class AbstractCacheMap<K, V> implements Cache<K, V> {

	class CacheObject<K2, V2> {
		CacheObject(K2 key, V2 value, long ttl) {
			this.key = key;
			this.cachedObject = value;
			this.ttl = ttl;
			this.lastAccess = System.currentTimeMillis();
		}

		final K2 key;
		final V2 cachedObject;
		long lastAccess; // ������ʱ��
		long accessCount; // ���ʴ���
		long ttl; // ������ʱ��(time-to-live)

		boolean isExpired() {
			if (ttl == 0) {
				return false;
			}
			return lastAccess + ttl < System.currentTimeMillis();
		}

		V2 getObject() {
			lastAccess = System.currentTimeMillis();
			accessCount++;
			return cachedObject;
		}
	}

	protected Map<K, CacheObject<K, V>> cacheMap;

	private final ReentrantReadWriteLock cacheLock = new ReentrantReadWriteLock();
	private final Lock readLock = cacheLock.readLock();
	private final Lock writeLock = cacheLock.writeLock();

	protected int cacheSize; // �����С , 0 -> ������

	protected boolean existCustomExpire; // �Ƿ�����Ĭ�Ϲ���ʱ��

	public int getCacheSize() {
		return cacheSize;
	}

	protected long defaultExpire; // Ĭ�Ϲ���ʱ��, 0 -> ��������

	public AbstractCacheMap(int cacheSize, long defaultExpire) {
		this.cacheSize = cacheSize;
		this.defaultExpire = defaultExpire;
	}

	public long getDefaultExpire() {
		return defaultExpire;
	}

	protected boolean isNeedClearExpiredObject() {
		return defaultExpire > 0 || existCustomExpire;
	}

	public void put(K key, V value) {
		put(key, value, defaultExpire);
	}

	public void put(K key, V value, long expire) {
		writeLock.lock();
		try {
			CacheObject<K, V> co = new CacheObject<K, V>(key, value, expire);
			if (expire != 0) {
				existCustomExpire = true;
			}
			if (isFull()) {
				eliminate();
			}
			cacheMap.put(key, co);
		} finally {
			writeLock.unlock();
		}
	}

	/**
	 * {@inheritDoc}
	 */
	public V get(K key) {
		readLock.lock();
		try {
			CacheObject<K, V> co = cacheMap.get(key);
			if (co == null) {
				return null;
			}
			if (co.isExpired() == true) {
				cacheMap.remove(key);
				return null;
			}

			return co.getObject();
		} finally {
			readLock.unlock();
		}
	}

	public final int eliminate() {
		writeLock.lock();
		try {
			return eliminateCache();
		} finally {
			writeLock.unlock();
		}
	}

	/**
	 * ��̭�������ʵ��
	 * 
	 * @return
	 */
	protected abstract int eliminateCache();

	public boolean isFull() {
		if (cacheSize == 0) {// o -> ������
			return false;
		}
		return cacheMap.size() >= cacheSize;
	}

	public void remove(K key) {
		writeLock.lock();
		try {
			cacheMap.remove(key);
		} finally {
			writeLock.unlock();
		}
	}

	public void clear() {
		writeLock.lock();
		try {
			cacheMap.clear();
		} finally {
			writeLock.unlock();
		}
	}

	public int size() {
		return cacheMap.size();
	}

	public boolean isEmpty() {
		return size() == 0;
	}
}
