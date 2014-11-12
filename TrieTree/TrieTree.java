package TrieTree;

/**
 * �ֵ���ģ�棬Ĭ��ֻ����26��Сд��ĸ
 * �ṩhasStr��insert��countPrefix��preWalk��getRoot�ӿ�
 * @author 
 */
public class TrieTree {

	private final int SIZE = 26;  //ÿ���ڵ��ܰ������ӽڵ���������ҪSIZE��ָ����ָ���亢��
	private Node root;   //�ֵ����ĸ��ڵ�

	/**
	 * �ֵ����ڵ���
	 * @author Lenovo
	 */
	private class Node {
		private boolean isStr;   //��ʶ�ýڵ��Ƿ�Ϊĳһ�ַ����ն˽ڵ�
		private int num;         //��ʶ�����ýڵ���ַ��������ڼ���ǰ׺������ʱ����õ�
		private Node[] child;    //�ýڵ���ӽڵ�

		public Node() {
			child = new Node[SIZE];
			isStr = false;
			num = 1;
		}
	}

	public TrieTree() {
		root = new Node();
	}

	/**
	 * ����ֵ������Ƿ���ȫ�����ַ���word
	 * @param word
	 * @return
	 */
	public boolean hasStr(String word) {
		Node pNode = this.root;

		//����ַ�ȥ���
		for (int i = 0; i < word.length(); i++) {
			int index = word.charAt(i) - 'a';
			//���ֵ�����û�ж�Ӧ�Ľڵ㣬����word�ַ��������һ���ַ����ֵ����м���Ӧ�ڵ��isStr����Ϊfalse���򷵻�false
			if (pNode.child[index] == null
					|| (i + 1 == word.length() && pNode.child[index].isStr == false)) {
				return false;
			}
			pNode = pNode.child[index];
		}

		return true;
	}

	/**
	 * ���ֵ����в���һ������
	 * @param word
	 */
	public void insert(String word) {
		if (word == null || word.isEmpty()) {
			return;
		}
		Node pNode = this.root;
		for (int i = 0; i < word.length(); i++) {
			int index = word.charAt(i) - 'a';
			if (pNode.child[index] == null) {   //��������ڽڵ㣬��newһ��һ�ڵ�����ֵ���
				Node tmpNode = new Node();
				pNode.child[index] = tmpNode;
			} else {
				pNode.child[index].num++;       //����ֵ����и�·���ϴ��ڽڵ㣬��num��1����ʾ�ڸýڵ�����һ���µĵ��ʾ���
			}
			pNode = pNode.child[index];
		}
		pNode.isStr = true;
	}

	/**
	 * ͳ�����ֵ������ж��ٸ���������strΪǰ׺��
	 * @param str
	 * @return
	 */
	public int countPrefix(String str) {
		Node pNode = this.root;
		for (int i = 0; i < str.length(); i++) {
			int index = str.charAt(i) - 'a';
			if (pNode.child[index] == null) {
				return 0;
			} else {
				pNode = pNode.child[index];
			}
		}

		return pNode.num;
	}

	/**
	 * �������
	 * @param root
	 */
	public void preWalk(Node root) {
		Node pNode = root;
		for (int i = 0; i < SIZE; i++) {
			if (pNode.child[i] != null) {
				System.out.print((char) ('a' + i) + "--");
				preWalk(pNode.child[i]);
			}
		}
	}

	/**
	 * �����ֵ������ڵ�
	 * @return
	 */
	public Node getRoot() {
		return root;
	}

}
