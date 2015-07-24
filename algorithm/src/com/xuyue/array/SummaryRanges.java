package com.xuyue.array;

import java.util.LinkedList;
import java.util.List;


/**
 * https://leetcode.com/problems/summary-ranges/
 * 
 * @author xuyue
 *
 */
public class SummaryRanges {
	public List<String> summaryRanges(int[] nums) {
		List<String> result = new LinkedList<String>();
		int N = nums.length;
		if (N == 0) {
			return result;
		}
		int i=0, j=1;
		while (j < N) {
			if (nums[j++] != nums[j-2]+1) {
				String tmp;
				if (i != j-2) {
					tmp = nums[i] + "->" + nums[j-2];
				}else {
					tmp = Integer.toString(nums[i]);
				}
				 result.add(tmp);
				 i = j-1;
			}
		}
		String tmp;
		if (i != j-1) {
			tmp = nums[i] + "->" + nums[j-1];
		}else {
			tmp = Integer.toString(nums[i]);
		}
		 result.add(tmp);
		return result;
	}
	
	public static void main(String[] args) {
		SummaryRanges summaryRanges = new SummaryRanges();
		int[] input = {1,2,3,5,7,8};
		List<String> result = summaryRanges.summaryRanges(input);
		System.out.println(result.toString());
	}
	
	
}
