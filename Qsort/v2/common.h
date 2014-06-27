/*************************************************************************
    > File Name: common.h
    > Author: xuyue
    > Mail: xuyue0531@gmail.com 
    > Created Time: 2014年05月13日 星期二 22时03分21秒
 ************************************************************************/

#ifndef COMMON_H
#define COMMON_H

#include<iostream>
using namespace std;


int writeinFile(ofstream&, int*, int);

int rand_r(unsigned int);


inline void exchange(int *a, int *b)
{	
	if(a != b)
	{
		int tmp;
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

#endif
