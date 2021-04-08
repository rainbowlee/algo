#pragma once
#include <string>
using namespace std;
struct Node;
//基于链表的栈实现
class Stack
{
public:
	Stack();
	bool Push(int value);
	bool Pop ();
	bool Top (int& value);
	int Count();
	int Cap();
	string ToString();
private:
	Node*	mCur;
	Node*	mSentinel;
	int		mCount;
	int		mN;
};