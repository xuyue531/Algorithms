package com.xuyue.array;

import java.util.Arrays;

/**
 * https://leetcode.com/problems/plus-one/
 * 
 * @author xuyue
 *
 */
public class PlusOne {

	public int[] plusOne(int[] digits) {
		int N = digits.length;
		boolean flag = true;
		for (int i = N; i > 0; --i) {
			int tmp = digits[i-1];
			if (flag) {
				flag = ((tmp+1)/10 == 1);
				digits[i-1] = (tmp+1)%10;
			}else {
				return digits;
			}
		}
		int[] newArr = digits;
		if (flag) {
			newArr = new int[N+1];
			newArr[0] = 1;
			System.arraycopy(digits, 0, newArr, 1, N);
		}
		return newArr;
	}
	
	
	public static void main(String[] args) {
		PlusOne plusOne = new PlusOne();
		int[] input = {9,0};
		int result[] = plusOne.plusOne(input);
		System.out.println(Arrays.toString(result));
	}

}
