package com.xuyue.string;

/**
 * 
 * @author xuyue
 *
 */
public class LongestPalindrome {
	
	public String process(String str) {
		String tStr = preProcess(str);
		System.out.println(tStr);
		int tLen = tStr.length();
		int[] p = new int[tLen];
		int mx = 0;
		int id = 0;
		for (int i = 1; i < tLen-1; i++) {
			int j = 2*id - i;
			p[i] = mx>i ? Integer.min(p[j], mx-i) : 1;
			while (tStr.charAt(i + p[i]) == tStr.charAt(i - p[i])) {
				p[i]++;
			}
			if (i + p[i] > mx) {
				mx = i + p[i];
				id = i;
			}
		}
		
		int maxLen = 0;
		int maxI = 0;
		for (int i = 0; i < tLen; i++) {
			if (p[i] > maxLen) {
				maxLen = p[i];
				maxI = i;
			}
		}
		
		String result = tStr.substring(maxI-maxLen+1, maxI+maxLen-1);
		StringBuilder strbuBuilder = new StringBuilder();
		for (int i = 0; i < result.length(); i++) {
			if (!("#".equals(result.substring(i, i+1)))) {
				strbuBuilder.append(result.charAt(i));
			}
		}
		
		return strbuBuilder.toString();
	}

	private String preProcess(String str) {
		int len = str.length();
		if (len == 0) 
			return "";
		StringBuilder strBuilder = new StringBuilder("^");
		for (int i = 0; i < len; i++) 
			strBuilder.append("#").append(str.charAt(i));
		strBuilder.append("#$");
		
		return strBuilder.toString();
	}
	
	
	public static void main(String[] args) {
		LongestPalindrome longestPalindrome = new LongestPalindrome();
		String s = longestPalindrome.process("123132345");
		System.out.println(s);
	}
	
	
}
