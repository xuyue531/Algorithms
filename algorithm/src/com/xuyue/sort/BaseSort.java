package com.xuyue.sort;

public abstract class BaseSort {

	protected static void exch(Comparable[] a, int j, int i) {
			Comparable tmp = a[j];
			a[j] = a[i];
			a[i] = tmp;
		}
	
	protected static boolean less(Comparable a, Comparable b) {
		return a.compareTo(b) < 0;
	}
	

}
