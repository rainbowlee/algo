#ifndef _TEST_H_
#define _TEST_H_
#pragma once
#include <vector>
using namespace std;

typedef void (*PTESTFUNC)() ;

struct FuncItem
{
	FuncItem()
	{

	}
	int a;

	PTESTFUNC func;
	//void (PTESTFUNC)();
};

class FuncMain
{
public:
	vector<FuncItem*> m_TestMethods;
	void AddMethod(FuncItem* funcItem)
	{
		m_TestMethods.push_back(funcItem);
	}

	void AddMethod(PTESTFUNC pfunc)
	{
		FuncItem* funcItem = new FuncItem();
		funcItem->func = pfunc;
		m_TestMethods.push_back(funcItem);
	}


	static FuncMain* Instance()
	{
		static FuncMain sFuncMai;
		return &sFuncMai;
	}


	void RunTests()
	{
		for( size_t i = 0; i < m_TestMethods.size(); ++i)
		{
			m_TestMethods[i]->func();
		}
	}
};
#endif
