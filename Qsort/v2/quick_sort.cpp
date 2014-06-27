/*************************************************************************
    > File Name: quick_sort.cpp
    > Author: xuyue
    > Mail: xuyue0531@gmail.com 
    > Created Time: 2014年05月13日 星期二 19时16分27秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<sys/time.h>
#include<string.h>
#include"common.h"
using namespace std;


clock_t spendofTime(int *data, const int len, void(*func)(int*, int, int))
{
	clock_t start, end;
	int *tmp_data = NULL;
	ofstream file;
	file.open("debug.log", ofstream::out | ofstream::app);

	file << "#1" << endl;
	writeinFile(file, data, len);

	tmp_data = (int*)malloc(len*sizeof(int));
	memcpy(tmp_data, data, len*(sizeof(int)));

	file << "#2" << endl;
	writeinFile(file, tmp_data, len);

	start = clock();
	func(tmp_data, 0, len-1);
	end = clock();

	file << "#3" << endl;
	writeinFile(file, tmp_data, len);

	free(tmp_data);
	return (end - start);
}



int partition(int a[], int low, int high)  
{
	int pi, tmp;
	int i, j;
	if(low < high)
	{
		i = low-1;
		pi = a[high]; 
		for(j = low; j <= high-1; ++j)
		{
			if(a[j] <= pi)
			{
				++i;
				if(i != j)
				{
					tmp = a[i];
					a[i] = a[j];
					a[j] = tmp;
				}
			//	exchange(&a[i], &a[j]);
			}
		}
		exchange(&a[i+1], &a[high]);
		return i+1;
	}
	else
		return -1;
} 



int partition_random(int a[], int low, int high)  
{
	if(high <= low)
		return -1;
//	timeval now;
//	gettimeofday(&now,NULL);
//	srand(now.tv_usec);
//	cout << "low: " << low << endl;
//	cout << "high: " << high << endl;
//	int num = (rand()%(high-low+1))+low;
	int num = (rand_r(high)%(high-low+1))+low;
	/*Exchange the num*/
	exchange(&a[num], &a[high]);

	return partition(a, low, high);
}



void quick_sort(int a[], int low, int high)  
{
	int pivot_pos;
	pivot_pos = partition(a, low, high);
	if(pivot_pos == -1) 
		return; 
	quick_sort(a, low, pivot_pos-1);
	quick_sort(a, pivot_pos+1, high);
}  


void quick_sort_random(int a[], int low, int high)  
{
	int pivot_pos;
	pivot_pos = partition_random(a, low, high);
	if(pivot_pos == -1) 
		return; 
	quick_sort_random(a, low, pivot_pos-1);
	quick_sort_random(a, pivot_pos+1, high);
} 


