/*************************************************************************
    > File Name: common.cpp
    > Author: xuyue
    > Mail: xuyue0531@gmail.com 
    > Created Time: 2014年05月13日 星期二 22时01分12秒
 ************************************************************************/

#include<iostream>
#include<fstream>
using namespace std;


int writeinFile(ofstream &file, int *data, int len)
{
	if(file.good())
	{
		int i, count;
		for(i=0, count=1; i < len-1; ++i, ++count)
		{
			file << data[i] <<',';
			if(count == 32)
			{
				file << endl;
				count = 1;
			}
		}
		file << data[i] << endl;
	}
	else
	{
		cerr << "the ostream is bad!" << endl;
		file.close();
		return -1;
	}
	return 0;
}



int rand_r(unsigned int seed)  
{

	unsigned int next = seed;  
	int result;  

	next *= 1103515245;  
	next += 12345;  
	result = (unsigned int) (next / 65536) % 2048;  

	next *= 1103515245;  
	next += 12345;  
	result <<= 10;  
	result ^= (unsigned int) (next / 65536) % 1024;  

	next *= 1103515245;  
	next += 12345;  
	result <<= 10;  
	result ^= (unsigned int) (next / 65536) % 1024;    

	return result;  
} 


