package com.PDR.section2;

public class Permutation2 {
	
	public static String nextPerm(String aStr) {
		int index_j = -1;
		int index_k = -1;
		int length = aStr.length();
		StringBuffer buffer = new StringBuffer(aStr);
		
		for (int i = length-1; i > 0; i--) {
			if (aStr.charAt(i) > aStr.charAt(i-1)) {
				index_j = i-1;
				break;
			}
		}
		if (index_j != -1) {
			for (int i = length-1; i > index_j; i--) {
				if (aStr.charAt(i) > aStr.charAt(index_j)) {
					index_k = i;
					break;
				}
			}
		}else {
			return null;
		}
		
		char tmp = buffer.charAt(index_j);
		buffer.setCharAt(index_j, buffer.charAt(index_k));
		buffer.setCharAt(index_k, tmp);
		
		StringBuffer subBuffer1 = new StringBuffer(buffer.subSequence(index_j+1, length));
		String subBuffer2 = buffer.substring(0, index_j+1);
		subBuffer1.reverse();
		
		return subBuffer2 + subBuffer1;
	}
	
	public static void main(String[] args) {
		String aNum = "123";
		while ((aNum = Permutation2.nextPerm(aNum)) != null) {
			System.out.println(aNum);
		}
	}
}
