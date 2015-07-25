package com.xuyue.array;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * https://leetcode.com/problems/pascals-triangle/
 * 
 * @author xuyue
 *
 */
public class PascalTriangle {
	public List<List<Integer>> generate(int numRows) {
		List<List<Integer>> result = new ArrayList<List<Integer>>();
		List<Integer> preline = null;
		if (numRows < 1) {
			return result;
		}
		int i=0;
		while (i < numRows) {
			List<Integer> line = new ArrayList<Integer>(i+1);
			for (int j = 0; j < i+1; j++) {
				if (j==0 || j==i) {
					line.add(1);
				}else {
					int val = preline.get(j-1) + preline.get(j);
					line.add(val);
				}
			}
			preline = line;
			result.add(line);
			++i;
		}
		return result;
	}
	
	
	public List<List<Integer>> generate2(int numRows) {
		List<List<Integer>> result = new ArrayList<List<Integer>>();
		for (int i = 0; i < numRows; i++) {
			List<Integer> line = new ArrayList<Integer>(Arrays.asList(1));
			for (int j = 1; j < i; j++) {
				line.add(result.get(i-1).get(j-1) + result.get(i-1).get(j));
			}
			if (i>0) {
				line.add(1);
			}
			result.add(line);
		}
		return result;
	}
	
	
	public static void main(String[] args) {
		PascalTriangle pascalTriangle = new PascalTriangle();	
		int input = 4;
		List<List<Integer>> result = pascalTriangle.generate2(input);
		System.out.println(result.toString());
	}
	
}
