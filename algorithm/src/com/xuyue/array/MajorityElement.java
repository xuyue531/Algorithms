package com.xuyue.array;

import java.util.Arrays;

/**
 * https://leetcode.com/problems/majority-element/
 * @author xuyue
 *
 */
public class MajorityElement {

	public int majorityElement(int[] nums) {
		int N = nums.length;
		Arrays.sort(nums);
		int result = nums[N/2];
		return result;
	}

	public static void main(String[] args) {
		MajorityElement majorityElement = new MajorityElement();
		int[] input = {1,2,3,3,4,4,5,4,2,1,2,2,2};
		int result = majorityElement.majorityElement(input);
		System.out.println(result);
	}
	
}
