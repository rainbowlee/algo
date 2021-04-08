#include "Test.h"
#include "LinkedNode.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>
void  TestRevert()
{
	Node* pHead = nullptr;
	for( int i = 1; i < 10; i++)
		pHead = LinkedNode::AddTailNode(pHead, i);

	string str = LinkedNode::ToString(pHead);
	printf(str.c_str());
	printf("\r\n");
	

	pHead = LinkedNode::Revert(pHead);
	str = LinkedNode::ToString(pHead);
	printf(str.c_str());
	printf("\r\n");
}


void  TestMerge()
{
	Node* pHead1 = nullptr;
	Node* pHead2 = nullptr;
	for( int i = 1; i < 18; i++)
		if(i%2 == 0)
			pHead2 = LinkedNode::AddTailNode(pHead2, i);
		else
			pHead1 = LinkedNode::AddTailNode(pHead1, i);

	string str = LinkedNode::ToString(pHead1);
	printf(str.c_str());
	printf("\r\n");

	str = LinkedNode::ToString(pHead2);
	printf(str.c_str());
	printf("\r\n");

	Node* pMerge = LinkedNode::Merge(pHead2,pHead1);
	str = LinkedNode::ToString(pMerge);
	printf(str.c_str());
	printf("\r\n");
}

void  TestDelLastN()
{
	Node* pHead1 = nullptr;
	for( int i = 1; i < 2; i++)
		pHead1 = LinkedNode::AddTailNode(pHead1, i);

	string str = LinkedNode::ToString(pHead1);
	printf(str.c_str());
	printf("\r\n");


	Node* pDelete = LinkedNode::DeleLastN(pHead1,1);
	str = LinkedNode::ToString(pDelete);
	printf(str.c_str());
	printf("\r\n");
}

void  TestDelLastN2()
{
	Node* pHead1 = nullptr;
	for( int i = 1; i < 10; i++)
		pHead1 = LinkedNode::AddTailNode(pHead1, i);

	string str = LinkedNode::ToString(pHead1);
	printf(str.c_str());
	printf("\r\n");


	Node* pDelete = LinkedNode::DeleLastN(pHead1,3);
	str = LinkedNode::ToString(pDelete);
	printf(str.c_str());
	printf("\r\n");
}


void  TestDelLastN3()
{
	Node* pHead1 = nullptr;
	for( int i = 1; i < 10; i++)
		pHead1 = LinkedNode::AddTailNode(pHead1, i);

	string str = LinkedNode::ToString(pHead1);
	printf(str.c_str());
	printf("\r\n");


	Node* pDelete = LinkedNode::DeleLastN(pHead1,5);
	str = LinkedNode::ToString(pDelete);
	printf(str.c_str());
	printf("\r\n");
}


void  TestCheckRing()
{

}


void  TestMid()
{
	Node* pHead1 = nullptr;
	for( int i = 1; i < 10; i++)
		pHead1 = LinkedNode::AddTailNode(pHead1, i);

	string str = LinkedNode::ToString(pHead1);
	printf(str.c_str());
	printf("\r\n");

	Node* midNode = LinkedNode::GetMid(pHead1);
	str.clear();
	if(midNode)
		str += std::to_string(midNode->mData);

	printf(str.c_str());
	printf("\r\n");
}


void  TestMid2()
{
	Node* pHead1 = nullptr;
	for( int i = 1; i < 9; i++)
		pHead1 = LinkedNode::AddTailNode(pHead1, i);

	string str = LinkedNode::ToString(pHead1);
	printf(str.c_str());
	printf("\r\n");

	Node* midNode = LinkedNode::GetMid(pHead1);
	str.clear();
	if(midNode)
		str += std::to_string(midNode->mData);

	printf(str.c_str());
	printf("\r\n");
}


void  TestHuWen1()
{
	Node* pHead1 = nullptr;
	for( int i = 1; i <= 9; i++)
		pHead1 = LinkedNode::AddTailNode(pHead1, i);

	for( int i = 9; i >=1; i--)
		pHead1 = LinkedNode::AddTailNode(pHead1, i);

	bool test = LinkedNode::CheckHuiWen(pHead1);

	if(test == false)
	{
		printf("TestHuWen1 error");
		printf("\r\n");
	}else{
		printf("TestHuWen2 s\r\n");
	}
	string str = LinkedNode::ToString(pHead1);
	printf(str.c_str());
	printf("\r\n");

}

void  TestHuWen2()
{
	Node* pHead1 = nullptr;
	for( int i = 1; i <= 9; i++)
		pHead1 = LinkedNode::AddTailNode(pHead1, i);

	pHead1 = LinkedNode::AddTailNode(pHead1, 1);

	for( int i = 9; i >= 1; i--)
		pHead1 = LinkedNode::AddTailNode(pHead1, i);

	bool test = LinkedNode::CheckHuiWen(pHead1);
	if(test == false)
	{
		printf("TestHuWen2 error");
		printf("\r\n");
	}
	else
	{
		printf("TestHuWen2 s\r\n");
	}

	string str = LinkedNode::ToString(pHead1);
	printf(str.c_str());
	printf("\r\n");
}

class TESTA
{
public:
	TESTA()
	{
		Register();
	}


	void Register()
	{
		//FuncItem* funcItem = (FuncItem *)malloc(sizeof(FuncItem));  //new FuncItem();
		//funcItem->func =TestRevert;

		//FuncMain::Instance()->AddMethod(funcItem);
		FuncMain::Instance()->AddMethod(TestRevert);
		FuncMain::Instance()->AddMethod(TestMerge);
		FuncMain::Instance()->AddMethod(TestDelLastN);	
		FuncMain::Instance()->AddMethod(TestDelLastN2);	
		FuncMain::Instance()->AddMethod(TestDelLastN3);	
		FuncMain::Instance()->AddMethod(TestCheckRing);	
		FuncMain::Instance()->AddMethod(TestMid);	
		FuncMain::Instance()->AddMethod(TestMid2);	
		FuncMain::Instance()->AddMethod(TestHuWen1);	
		FuncMain::Instance()->AddMethod(TestHuWen2);	
	}
};

static TESTA a;