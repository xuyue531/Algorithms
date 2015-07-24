package com.xuyue.array;

import java.util.Arrays;

/**
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 * 
 * @author xuyue
 *
 */
public class RemvDupfromSortedArr {
	
	public int removeDuplicates(int[] nums) {
		int N = nums.length;
		if (N == 0) {
			return 0;
		}
		int i=1, j=1;
		while (j < N) {
			if (nums[j++] != nums[j-2]) {
				nums[i++] = nums[j-1];
			}
		}
		return i;
	}
	
	public static void main(String[] args) {
		RemvDupfromSortedArr remvDupfromSortedArr = new RemvDupfromSortedArr();
		int[] input = {1,2,2,2,3,3,4,4};
		int len = remvDupfromSortedArr.removeDuplicates(input);
		System.out.println(Arrays.toString(input));
		System.out.println(len);
	}
	
}
