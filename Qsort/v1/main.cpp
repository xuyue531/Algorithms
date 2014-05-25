/*************************************************************************
    > File Name: quick_sort.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2014年03月18日 星期二 12时27分05秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
#include<sys/time.h>
#include<string.h>

#include"quick_sort.h"
#include"common.h"
using namespace std;
const int NUM = 100000;


int main()
{
	int i, ret;
	clock_t range;
	int *data1, 
		*data2;
	ofstream outfile;
	timeval time;

	/*init data*/
	//init data1(Ordered)
	data1 = (int*)malloc(NUM*(sizeof(int)));
	for(i = 0; i < NUM; ++i)
		data1[i] = i;
	//init data2(Disorder)
	data2 = (int*)malloc(NUM*(sizeof(int)));
	gettimeofday(&time, NULL);
	srand(time.tv_usec);
	for(i = 0; i < NUM; ++i)
	{
		data2[i] = (rand()%NUM);
	}

	/*write the data in file*/
	outfile.open("data.log", ofstream::out | ofstream::app);
	outfile << "data1: " << endl;
	if((ret = writeinFile(outfile, data1, NUM)) == -1)
		return -1;
	outfile << "data2: " << endl;
	if((ret = writeinFile(outfile, data2, NUM)) == -1)
		return -1;
	outfile.close();

	/*test Performance of the algorithm*/
	//normal quick sort version
	range = spendofTime(data1, NUM, quick_sort);
	cout << "time range[data1]: " <<((double)range/CLOCKS_PER_SEC) <<" seconds " << endl;
	range = spendofTime(data2, NUM, quick_sort);
	cout << "time range[data2]: " <<((double)range/CLOCKS_PER_SEC) <<" seconds " << endl;
	//random quick sort version
	range = spendofTime(data1, NUM, quick_sort_random);
	cout << "time range[random_data1]: " <<((double)range/CLOCKS_PER_SEC) <<" seconds " << endl;
	range = spendofTime(data2, NUM, quick_sort_random);
	cout << "time range[random_data2]: " <<((double)range/CLOCKS_PER_SEC) <<" seconds " << endl;


	free(data1);
	free(data2);
	return 0;
}




