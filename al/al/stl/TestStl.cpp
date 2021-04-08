#include "TestStl.h"

#include "../Test.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>


void  TestPriority_Queue()
{
	queue<int> q;
	for (int i = 1; i <= 5; i++)
	{
		q.push(i * 10);
		cout << "push element " << i << endl;
	}
	q.push(15);
	q.push(4);
	int size = q.size();
	int i = 1;
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		cout << "No " << i++ << " element is: " << temp << endl;
	}
}


void  TestDequeue()
{
	deque<int> d;
	for(int i = 1; i < 7; i ++)
		d.push_back(i);

	int size = d.size();

	d.pop_front();
	d.pop_front();

	auto iter = std::find(d.begin(), d.end(), 3);
	if (iter != d.end())
		d.erase(iter);

	deque<int>::iterator it;
	for(it = d.begin(); it != d.end(); it ++)
		cout<<*it<<" ";
	cout<<endl;

	d.pop_back();
	for(it = d.begin(); it != d.end(); it ++)
		cout<<*it<<" ";
	cout<<endl;

	d.erase(d.begin()+1);
	for(it = d.begin(); it != d.end(); it ++)
		cout<<*it<<" ";
	cout<<endl;

	d.clear();
	cout<<d.size()<<endl;
}

struct cmp
{ //这个比较要用结构体表示
	bool operator()(int &a, int &b) const
	{
		return a > b;
	}
};

void  TestPriority_PriorityQueue()
{
	priority_queue<int, vector<int>, cmp> q;
	for (int i = 1; i <= 5; i++)
	{
		q.push(i * 10);
		cout << "push element " << i << endl;
	}
	q.push(15);
	q.push(4);
	int size = q.size();
	int i = 1;
	while (!q.empty())
	{
		int temp = q.top();
		q.pop();
		cout << "No " << i++ << " element is: " << temp << endl;
	}
}


void  TestPriority_Stack()
{
	stack<int> q;
	for (int i = 1; i <= 5; i++)
	{
		q.push(i * 10);
		cout << "push element " << i << endl;
	}
	q.push(15);
	q.push(4);
	int size = q.size();
	int i = 1;
	while (!q.empty())
	{
		int temp = q.top();
		q.pop();
		cout << "No " << i++ << " element is: " << temp << endl;
	}
}



class TESTSTL
{
public:
	TESTSTL()
	{
		Register();
	}


	void Register()
	{
		FuncMain::Instance()->AddMethod(TestPriority_Queue);
		FuncMain::Instance()->AddMethod(TestDequeue);
		FuncMain::Instance()->AddMethod(TestPriority_PriorityQueue);

		FuncMain::Instance()->AddMethod(TestPriority_Stack);
	}
};

static TESTSTL a;