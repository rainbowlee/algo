#pragma once
#include <vector>
using namespace std;
class Sort
{
public:
	//ð��
	static void BubbleSort( int arr[] , int len);
	//����
	static void InsertSort(int arr[], int len);
	//ѡ��
	static void SelectSort(int arr[], int len);
	//�鲢����
	static void MergeSort(vector<int>& arr);
	//��������
	static void QuickSort(vector<int>& arr);
	static int QuickPartition(vector<int>& arr, int from ,int to);
	//һ������������
	static void BucketSort(vector<int>& arr);

	//��������
	static vector<int> CountSort(vector<int>& arr);
	//��������
	static void BaseSort(vector<int>& arr);
};