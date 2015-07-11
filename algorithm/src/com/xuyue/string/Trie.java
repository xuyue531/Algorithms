package com.xuyue.string;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;


public class Trie<Value> {
	
	private static int R = 256;
	private Node root;
	
	public Trie() {
	}
	
	
	/**
	 * 查找指定字符串的value值
	 * @param key
	 * @return
	 */
	public Value get(String key) {
		Node x = get(root, key, 0);
		if (x == null) {
			return null;
		}
		return (Value) x.val;
	}
	
	private Node get(Node x, String key, int d) {
		if (x == null) {
			return null;
		}
		if (d == key.length()) {
			return x;
		}
		char c = key.charAt(d);
		return get(x.next[c], key, d+1);
	}
	
	
	/**
	 * 将指定字符串插入trie树
	 * @param key
	 * @param val
	 */
	public void put(String key, Value val) {
		root = put(root, key, val, 0);
	}
	
	private Node put(Node x, String key, Value val, int d) {
		if (x == null) {
			x = new Node();
		}
		if (d == key.length()) {
			x.val = val;
			return x;
		}
		char c = key.charAt(d);
		x.next[c] = put(x.next[c], key, val, d+1);
		return x;
	}
	
	/**
	 * 得到trie树中所有的key
	 * @return
	 */
	public Iterable<String> keys() {
		return keysWithPrefix("");
	}
	
	/**
	 * 查询所有以pre为前缀的key
	 * @param pre
	 * @return
	 */
	public Iterable<String> keysWithPrefix(String pre) {
		Queue<String> queue = new LinkedList<String>();
		collect(get(root, pre, 0), pre, queue);
		return queue;
	}
	
	private void collect(Node x, String pre, Queue<String> q) {
		if (x == null) {
			return;
		}
		if (x.val != null) {
			q.add(pre);
		}
		for (char c = 0;  c < R; c++) {
			collect(x.next[c], pre+c, q);
		}
	}
	
	private static class Node {
		private Object val;
		private Node[] next = new Node[R];
	}
	
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Trie<Integer> trie = new Trie<Integer>();
		
		int inputSize = scanner.nextInt();
		System.out.println(inputSize);
		for (int i = 0; i < inputSize; i++) {
			String key = scanner.next();
			Integer old = trie.get(key);
			Integer newVal = old == null ? 1 : old+1;
			trie.put(key, newVal);
		}
		int querySize = scanner.nextInt();
		System.out.println(querySize);
		for (int i = 0; i < querySize; i++) {
			String str = scanner.next();
			Iterable<String> match = trie.keysWithPrefix(str);
			Iterator<String> matchIterator = match.iterator();
			int count = 0;
			while (matchIterator.hasNext()) {
				matchIterator.next();
				count++;
			}
			System.out.println(count);
		}
		
		
		
		
//		Trie<Integer> trie = new Trie<Integer>();
//		trie.put("abc", 1);
//		trie.put("asd", 1);
//		trie.put("ddsd", 1);
//		Integer n = trie.get("abc");
//		System.out.println("n is " + n);
//		Iterable<String> keys = trie.keys();
//		Iterator<String> iterator = keys.iterator();
//		while (iterator.hasNext()) {
//			String s = iterator.next();
//			System.out.println("keys: " + s);
//		}
//		Iterable<String> preFix = trie.keysWithPrefix("a");
//		Iterator<String> preIterator = preFix.iterator();
//		while (preIterator.hasNext()) {
//			String s = preIterator.next();
//			System.out.println("a: " + s);
//		}
		
	}
	
}
