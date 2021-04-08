#include "Stack.h"
#include "LinkedNode.h"
Stack::Stack()
{
	mSentinel = new Node();
	mCur = mSentinel;
	mCount = 0;
	mN = 0;
}


bool Stack::Push(int value)
{
	if(mCur->mPre != nullptr)
	{
		mCur = mCur->mPre;
		mCur->mData = value;
		mCount++;
		return true;
	}
	mN++;
	mCount++;
	mCur = LinkedNode::AddHeadNodeD(mCur, value);
	return false;
}

bool Stack::Pop()
{
	if(mCur == mSentinel)
		return false;
	mCount--;
	mCur = mCur->mNext;
	return true;
}

bool Stack::Top(int& value)
{
	if(mCur == mSentinel)
		return false;

	value = mCur->mData;
	return true;
}

int Stack::Count()
{
	return mCount;
}

int Stack::Cap()
{
	return mN;
}

string Stack::ToString()
{
	string str;
	Node* iter = mCur;
	while (iter != mSentinel)
	{
		str += "," + std::to_string(iter->mData) ;
		iter = iter->mNext;
	}

	return str;
}