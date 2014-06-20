/*************************************************************************
  > File Name: experiment_3.cpp
  > Author: xuyue
  > Mail: xuyue0531@gmail.com 
  > Created Time: 2014年06月20日 星期五 13时36分01秒
 ************************************************************************/

#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef struct Task {
	int id;
	int deadline;
	int w;
	int flag; 
} Task;

int cmp(const Task &t1, const Task &t2) {
	if(t1.flag < t2.flag)
		return 1;
	else if(t1.flag == t2.flag) {
		if(t1.deadline < t2.deadline)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}

int main() {
	freopen("data.in", "r", stdin);
	//	freopen("data.out", "w", stdout);

	int task_num;
	Task *task;

	cout << "Enter the num of task: " << endl;
	while(!(cin >> task_num)) {
		cout << "Find an error! Please input again: ";
	}

	task = (Task*)malloc(task_num*sizeof(Task));
	cout << "Please input your task information(id, deadline, w): " << endl;
	for(int i = 0; i < task_num; ++i) {
		cin >> task[i].id >> task[i].deadline >> task[i].w;
		if(cin.fail()) {
			cout << "bad data, try again:";
			cin.clear(istream::failbit);
			cin.ignore();
			continue;
		}
	}

	int t, count;
	for(int i = 0; i < task_num; ++i) {
		for(int j = 0; j <= i; ++j) {
			count = 0;
			t = j+1;
			for(int n = 0; n <= i; ++n) {
				if(task[n].flag == 0 && task[n].deadline <= t)
					++count;
			}
			if(count > t) {
				task[i].flag = 1;
				break;
			}
		}
	}

	sort(task, task + task_num, cmp);
	cout << "The result is: " << endl;
	for(int i = 0; i < task_num; ++i) {
		//if(task[i].flag == 0)
		cout << "id:" << task[i].id 
			<< " deadline:" << task[i].deadline
			<< " w:" << task[i].w
			<< " flag:" << task[i].flag <<endl;
	}

	free(task);
	return 0;
}

