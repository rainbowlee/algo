#include "Test.h"
#include "Sorting.h"

void TestSortBubble()
{
	int arr[10] = {1,4,2,7,9,8,0,5,12,3};
	Sort::BubbleSort(arr, 10);
}

void TestSortInsert()
{
	int arr[10] = {4,1,2,7,9,8,0,5,12,3};
	Sort::InsertSort(arr, 10);
}

void TestSortSelect()
{
	int arr[10] = {12,4,2,7,9,8,30,5,12,3};
	Sort::SelectSort(arr, 10);
}

void TestSortMerge()
{
	vector<int> arr;
	int arrtem[10] = {12,4,2,7,9,8,30,5,12,3};
	for(int i = 0; i < 10; i++)
		arr.push_back(arrtem[i]);

	Sort::MergeSort(arr);
}

void TestSortQuick()
{
	vector<int> arr;
	int arrtem[10] = {12,4,2,7,9,8,30,5,12,3};
	for(int i = 0; i < 10; i++)
		arr.push_back(arrtem[i]);

	Sort::QuickSort(arr);
}

void TestSortBucket()
{
	vector<int> arr;
	int arrtem[10] = {12,4,2,7,9,8,30,5,12,3};
	for(int i = 0; i < 10; i++)
		arr.push_back(arrtem[i]);

	Sort::BucketSort(arr);
}

void TestSortCount()
{
	vector<int> arr;
	int arrtem[10] = {12,4,2,7,9,8,30,5,12,3};
	for(int i = 0; i < 10; i++)
		arr.push_back(arrtem[i]);

	vector<int> paiming = Sort::CountSort(arr);
}

class TESTSort
{
public:
	TESTSort()
	{
		Register();
	}


	void Register()
	{
		FuncMain::Instance()->AddMethod(TestSortBubble);
		FuncMain::Instance()->AddMethod(TestSortInsert);
		FuncMain::Instance()->AddMethod(TestSortSelect);
		FuncMain::Instance()->AddMethod(TestSortMerge);
		FuncMain::Instance()->AddMethod(TestSortQuick);
		FuncMain::Instance()->AddMethod(TestSortCount);
		
	}
};

static TESTSort a;