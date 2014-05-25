/*************************************************************************
    > File Name: quick_sort.h
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2014年05月13日 星期二 19时20分35秒
 ************************************************************************/

using namespace std;



clock_t spendofTime(int*, const int, void(*func)(int*, int, int));

int partition(int*, int, int);

int partition_random(int*, int, int);

void quick_sort(int*, int, int);

void quick_sort_random(int*, int, int); 


