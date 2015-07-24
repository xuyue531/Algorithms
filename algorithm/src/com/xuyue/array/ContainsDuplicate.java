package com.xuyue.array;

import java.util.HashSet;
import java.util.Set;

/**
 * https://leetcode.com/problems/contains-duplicate/
 * @author xuyue
 *
 */
public class ContainsDuplicate {

	public boolean containsDuplicate1(int[] nums) {
		int[] surive = new int[(0x07FFFFFF) +1];
		for (int i = 0; i < surive.length; i++) {
			surive[i] = 0;
		}
		for (int i : nums) {
			int pos = i/32;
			if ((surive[pos] & (1<<(i%32))) == 0) {
				surive[pos] = surive[pos] | (1 << i%32);
			}else {
				return true;
			}
		}
		return false;
	}
	
	public boolean containsDuplicate2(int[] nums) {
		Node[] chain = new Node[256];
		for (int i : nums) {
			i = Math.abs(i);
			int pos = i % 256;
			if (chain[pos] == null) {
				Node node = new Node();
				node.setVal(i);
				chain[pos] = node;
			}else {
				Node pNode = chain[pos];
				Node preNode = pNode;
				while (pNode != null && pNode.val != i) {
					preNode = pNode;
					pNode = pNode.next;
				}
				if (pNode != null && pNode.val == i) {
					return true;
				}else if (preNode != null) {
					pNode = new Node();
					pNode.setVal(i);
					preNode.next = pNode;
				}
			}
		}
		return false;
    }
	
	public boolean containsDuplicate(int[] nums) {
		Set<Integer> set = new HashSet<Integer>();
		for (int i : nums) {
			if (!set.add(i)) {
				return true;
			}
		}
		return false;
    }
	
	
	
	class Node{
		int val;
		Node next;
		
		public int getVal() {
			return val;
		}
		public void setVal(int val) {
			this.val = val;
		}
		public Node getNext() {
			return next;
		}
		public void setNext(Node next) {
			this.next = next;
		}
		
	}
	
	
	public static void main(String[] args) {
		ContainsDuplicate containsDuplicate = new ContainsDuplicate();
		int[] input ={-3,2,-3,4};
		System.out.println(containsDuplicate.containsDuplicate1(input));
	}
	

}
