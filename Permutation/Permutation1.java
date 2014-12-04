package com.PDR.section2;

public class Permutation1 {
	
	private boolean[] used;
	private Integer[] perm;
	
	public void permSort(int num) {
		perm = new Integer[num];
		used = new boolean[num];
		permut(0, num);
	}
	
	private void permut(int pos, int n) {
		if (pos == n) {
			for (int i = 0; i < perm.length; i++) {
				System.out.print(perm[i]);
			}
			System.out.println();
			return;
		}
		for (int i = 0; i < n; i++) {
			if (used[i] == false) {
				perm[pos] = i;
				used[i] = true;
				permut(pos+1, n);
				used[i] = false;
			}
		}
	}
	
	public static void main(String[] args) {
		int num = 3;
		Permutation1 permutation = new Permutation1();
		permutation.permSort(num);
	}
	
}
