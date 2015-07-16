package com.xuyue.sort;

import java.util.Random;

/**
 * 插入排序
 * @author xuyue
 *
 */
public class Insertion extends BaseSort {

	public static void sort(Comparable[] a) {
		int N = a.length;
		for (int i = 1; i < N; i++) {
			for (int j = i; j > 0 && less(a[j], a[j-1]); j--) {
				exch(a, j, j-1);
			}
		}
	}

	/**
	 * 要大幅提高插入排序的速度并不难，
	 * 只需要在内循环中将较大的元素都向右移动而不总是交换两个元素（这样访问数组的次数就能减半）
	 * @param a
	 */
	public static void sort2(Comparable[] a) {
		int N = a.length;
		for (int i = 1; i < N; i++) {
			int j = i;
			Comparable tmp = a[j];
			for (; j > 0 && less(tmp, a[j-1]); j--) {
				a[j] = a[j-1];
			}
			a[j] = tmp;
		}
	}
	
	
	
	public static void main(String[] args) {
		int num = 10000;
		Random random = new Random(10000);
		Integer[] a = new Integer[num];
		for (int i = 0; i < a.length; i++) {
			a[i] = random.nextInt();
		}
		Integer[] b = new Integer[num];
		System.arraycopy(a, 0, b, 0, a.length);
//		System.out.println(Arrays.toString(a));
		long start = System.nanoTime();
		Insertion.sort(a);
		long end = System.nanoTime();
		int spend = (int) ((end - start)/1000);
		System.out.println("sort performance: " + spend);
		start = System.nanoTime();
		Insertion.sort2(b);
		end = System.nanoTime();
		spend = (int) ((end - start)/1000);
		System.out.println("sort2 performance: " + spend);
//		System.out.println(Arrays.toString(a));
	}
	
	
}
