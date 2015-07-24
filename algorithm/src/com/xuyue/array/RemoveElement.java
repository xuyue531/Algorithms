package com.xuyue.array;

/**
 * https://leetcode.com/problems/remove-element/
 * 
 * @author xuyue
 *
 */
public class RemoveElement {

	public int removeElement(int[] nums, int val) {
		int N = nums.length;
		int i=0, j=0;
		while (j < N) {
			if (nums[j++] != val) {
				nums[i++] = nums[j-1];
			}
		}
		return i;
	}
	
	public static void main(String[] args) {
		RemoveElement removeElement = new RemoveElement();
		int[] intput = {1,2,3,4,5,5};
		int len = removeElement.removeElement(intput, 4);
		System.out.println(len);
	}
	
}
