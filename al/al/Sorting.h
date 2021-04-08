#pragma once
#include <vector>
using namespace std;
class Sort
{
public:
	//冒泡
	static void BubbleSort( int arr[] , int len);
	//插入
	static void InsertSort(int arr[], int len);
	//选择
	static void SelectSort(int arr[], int len);
	//归并排序
	static void MergeSort(vector<int>& arr);
	//快速排序
	static void QuickSort(vector<int>& arr);
	static int QuickPartition(vector<int>& arr, int from ,int to);
	//一百以内数排序
	static void BucketSort(vector<int>& arr);

	//计数排序
	static vector<int> CountSort(vector<int>& arr);
	//基数排序
	static void BaseSort(vector<int>& arr);
};