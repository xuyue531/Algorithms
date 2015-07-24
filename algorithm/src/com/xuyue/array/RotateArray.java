package com.xuyue.array;

import java.util.Arrays;

/**
 * https://leetcode.com/problems/rotate-array/
 * 
 * @author xuyue
 *
 */
public class RotateArray {

	public void rotate(int[] nums, int k) {
		int N = nums.length;
		k = k % N;
		int i = 0, j = N-k-1;
		reversion(nums, i, j);
		i = N-k; j = N-1;
		reversion(nums, i, j);
		reversion(nums, 0, N-1);
	}
	
	public void reversion(int[] nums, int i, int j) {
		int tmp;
		while (i < j) {
			tmp = nums[i];
			nums[i++] = nums[j];
			nums[j--] = tmp;
		}
	}
	
	public static void main(String[] args) {
		RotateArray rotateArray = new RotateArray();
		int[] nums = {1,2,3};
		rotateArray.rotate(nums, 4);
		System.out.println(Arrays.toString(nums));
	}
	

}
