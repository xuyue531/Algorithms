package com.xuyue.string;

public class StrToInt {
	
	public static final int MAX_INT = Integer.MAX_VALUE;
	public static final int MIN_INT = Integer.MIN_VALUE;
	public static final long MIN_INT_ABS = (long)Integer.MAX_VALUE +1;
	
	
	public int paraseInt(String str) {
		if (str == null) {
			return 0;
		}
		
		long n = 0;
		String iStr = str.replace(" ", "");
		boolean sign = true;
		int index = 0;
		
		if ("-".equals(iStr.substring(0, 1))) {
			sign = false;
			++index;
		}else if ("+".equals(iStr.substring(0, 1))){
			++index;
		}
		
		for (; index < iStr.length(); ++index) {
			if (!isdigit(iStr.charAt(index))) {
				return 0;
			}
			int c = iStr.charAt(index) - '0';
			if (sign && ((n > MAX_INT/10) || (n == MAX_INT/10 && c > MAX_INT%10))) {
				n = MAX_INT;
				break;
			}else if (!sign && ((n > MIN_INT_ABS/10) || (n == MIN_INT_ABS/10 && c > MIN_INT_ABS%10))) {
				n = MIN_INT;
				break;
			}
			n = n*10 + c;
		}
		return sign?(int)n:(int)-n;
	}
	
	private boolean isdigit(char charAt) {
		if ((charAt - '0') > 9 || (charAt - '0') < 0) {
			return false;	
		}
		return true;
	}



	public static void main(String[] args) {
		StrToInt s2i = new StrToInt();
		System.out.println(s2i.paraseInt(" 2 42   3"));
	}
	

}
