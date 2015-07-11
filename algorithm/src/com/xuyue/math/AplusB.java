package com.xuyue.math;

import java.util.Scanner;


/**
 * http://hihocoder.com/problemset/problem/1000
 * @author xuyue
 *
 */
public class AplusB {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int a = 0;
		int b = 0;
		String line;
		while (scanner.hasNext()) {
			line = scanner.nextLine();
			String[] num = line.split(" +");
			try {
				a = Integer.parseInt(num[0]);
				b = Integer.parseInt(num[1]);
			} catch (Exception e) {
			}
			System.out.println(a+b);
		}
	}
	
}
