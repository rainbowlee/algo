#include "Searching.h"
#include "Test.h"
#include <assert.h> 
#include <iostream>

//循环有序二分查找
void TestBinarySearch1()
{
	vector<int> datas;
	datas.push_back(1212);
	datas.push_back(1215);
	datas.push_back(1216);

	datas.push_back(1122);
	datas.push_back(1125);
	datas.push_back(1126);

	datas.push_back(1112);
	datas.push_back(1115);
	datas.push_back(1116);

	datas.push_back(112);
	datas.push_back(115);
	datas.push_back(116);

	datas.push_back(12);
	datas.push_back(15);
	datas.push_back(16);


	datas.push_back(2);
	datas.push_back(5);
	datas.push_back(6);


	int res = Search::SearchBinaryXunHuanYouXu(datas,15);
	assert(res == 13);

	res = Search::SearchBinaryXunHuanYouXu(datas,12);
	assert(res == 12);

	res = Search::SearchBinaryXunHuanYouXu(datas,1000);
	assert(res == -1);

	res = Search::SearchBinaryXunHuanYouXu(datas,5);
	assert(res == 16);


	res = Search::SearchBinaryXunHuanYouXu(datas,6);
	assert(res == 17);


	res = Search::SearchBinaryXunHuanYouXu(datas,1215);
	assert(res == 1);

	res = Search::SearchBinaryXunHuanYouXu(datas,6);
	assert(res == 17);

	res = Search::SearchBinaryXunHuanYouXu(datas,1212);
	assert(res == 0);

	std::cout << ( 2 > 1 ) ? 2 : 1;
}


void TestBinarySearch2()
{
	vector<int> datas;
	datas.push_back(1212);
	datas.push_back(1215);
	datas.push_back(1216);

	datas.push_back(1122);
	datas.push_back(1125);
	datas.push_back(1126);

	datas.push_back(1112);
	datas.push_back(1115);
	datas.push_back(1116);

	datas.push_back(112);
	datas.push_back(115);
	datas.push_back(116);

	datas.push_back(12);
	datas.push_back(15);
	datas.push_back(16);


	datas.push_back(2);
	datas.push_back(5);
	datas.push_back(6);


	//int res = Search::SearchBinaryXunHuanYouXu2(datas,15);
	//assert(res == 13);

	//res = Search::SearchBinaryXunHuanYouXu2(datas,12);
	//assert(res == 12);

	//res = Search::SearchBinaryXunHuanYouXu2(datas,1000);
	//assert(res == -1);

	//res = Search::SearchBinaryXunHuanYouXu2(datas,5);
	//assert(res == 16);


	//res = Search::SearchBinaryXunHuanYouXu2(datas,6);
	//assert(res == 17);


	//res = Search::SearchBinaryXunHuanYouXu2(datas,1215);
	//assert(res == 1);
}


class TESTSearch
{
public:
	TESTSearch()
	{
		Register();
	}


	void Register()
	{
		FuncMain::Instance()->AddMethod(TestBinarySearch1);
		FuncMain::Instance()->AddMethod(TestBinarySearch2);
	}
};

static TESTSearch a;