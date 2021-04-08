#include "Searching.h"

static void GetMinMaxIndex(vector<int>& datas, int pos, int& min, int& max)
{
	int posData = datas[pos];

	min = pos;
	max = pos;
	for(size_t i = pos+1; i < datas.size(); i++)
	{
		if(datas[i] > posData)
			max++;
		else
			break;
	}

	for(int i = pos-1; i >=0; --i)
	{
		if(datas[i] < posData)
			min--;
		else
			break;
	}
}

 int Search::SearchBinary(vector<int>& datas, int findData)
 {
	int begin = 0;
	int end = datas.size()-1;

	while (begin<=end)
	{
		int mid = begin + ((end-begin) >> 1);
		if(datas[mid]==findData)
			return mid;

		if(datas[mid] < findData)
			begin = mid + 1;
		else
			end = mid - 1;
	}

	return -1;
 }

 //存在相等情况
 int Search::SearchBinaryFirst(vector<int>& datas, int findData)
 {
	 int begin = 0;
	 int end = datas.size()-1;

	 while (begin<=end)
	 {
		 int mid = begin + ((end-begin) >> 1);
		 if(datas[mid] == findData)
		 {
			 if(mid == 0 || datas[mid-1] != findData) return mid;
			 end = mid - 1;
		 }
		 else if(datas[mid] < findData)
			 begin = mid + 1;
		 else
			 end = mid - 1;
	 }

	 return -1;
 }

 //存在相等情况
 int Search::SearchBinaryLast(vector<int>& datas, int findData)
 {
	 int begin = 0;
	 int end = datas.size()-1;

	 while (begin<=end)
	 {
		 int mid = begin + ((end-begin) >> 1);
		 if(datas[mid] == findData)
		 {
			 if(mid == datas.size()-1 || datas[mid+1] != findData) return mid;
			 begin = mid + 1;
		 }
		 else if(datas[mid] < findData)
			 begin = mid + 1;
		 else
			 end = mid - 1;
	 }

	 return -1;
 }

 //存在相等情况
 int Search::SearchBinaryFirstGE(vector<int>& datas, int findData)
 {
	 int begin = 0;
	 int end = datas.size()-1;

	 while (begin<=end)
	 {
		 int mid = begin + ((end-begin) >> 1);
		 if(datas[mid] >= findData)
		 {
			 if(mid == 0 || datas[mid-1] < findData) return mid;
			 end = mid - 1;
		 }
		 else if(datas[mid] < findData)
			 begin = mid + 1;
		 else
			 end = mid - 1;
	 }

	 return -1;
 }

 //存在相等情况
 int Search::SearchBinaryLastLE(vector<int>& datas, int findData)
 {
	 int begin = 0;
	 int end = datas.size()-1;

	 while (begin<=end)
	 {
		 int mid = begin + ((end-begin) >> 1);
		 if(datas[mid] <= findData)
		 {
			 if(mid == datas.size()-1 || datas[mid+1] > findData) return mid;
			 begin = mid + 1;
		 }
		 else if(datas[mid] < findData)
			 begin = mid + 1;
		 else
			 end = mid - 1;
	 }

	 return -1;
 }

int Search::SearchBinaryXunHuanYouXu(vector<int>& datas, int findData)
{
	int begin = 0;
	int end = datas.size()-1;

	while (begin<=end)
	{
		int mid = begin + (end- begin)/2;

		if(datas[mid] == findData)
			return mid;

		//一个区间 begin  < end , mid >  begin mid < end
		if(datas[begin] < datas[end])
		{
			if(datas[mid] < findData)
				begin= mid+1;
			else
				end = mid - 1; 
			continue;
		}

		int midmax;
		int midmin;
		GetMinMaxIndex(datas, mid, midmin, midmax);
		if(datas[midmin] <= findData && findData <= datas[midmax])
		{
			int mid = midmin + (midmax- midmin)/2;
			
			if(datas[mid] == findData)
				return mid;

			if(datas[midmin] == findData)
				return midmin;

			if(datas[midmax] == findData)
				return midmax;

			if(datas[midmin] < findData)
			{
				begin= mid+1;
				end = midmax;
			}
			else
			{
				begin = midmin;
				end = mid - 1; 
			}
			continue;
		}


		int beginmax;
		int beginmin;
		GetMinMaxIndex(datas, begin, beginmin, beginmax);
		if(datas[beginmin] <= findData && findData <= datas[beginmax])
		{
			int mid = beginmin + (beginmax- beginmin)/2;

			if(datas[mid] == findData)
				return mid;

			if(datas[beginmin] == findData)
				return beginmin;

			if(datas[beginmax] == findData)
				return beginmax;

			if(datas[beginmin] < findData)
			{
				begin= mid+1;
				end = beginmax;
			}
			else
			{
				begin = beginmin;
				end = mid - 1; 
			}
			continue;
		}

		int endmax;
		int endmin;
		GetMinMaxIndex(datas, end, endmin, endmax);
		if(datas[endmin] <= findData && findData <= datas[endmax])
		{
			int mid = endmin + (endmax- endmin)/2;
			if(datas[mid] == findData)
				return mid;

			if(datas[endmin] == findData)
				return endmin;

			if(datas[endmax] == findData)
				return endmax;

			if(datas[endmin] < findData)
			{
				begin= mid+1;
				end = endmax;
			}
			else
			{
				begin = endmin;
				end = mid - 1; 
			}
			continue;
		}
		// finddata 属于任何一个区间都是直接去找就ok啦

		//肯定是跨区间啦
		//left
		if(findData > datas[midmin])
		{
			end = midmin-1;
		}
		//right
		else if(findData < datas[midmax])
		{
			begin = midmax+1;
		}
	}

	return -1;
}


int SearchBinaryXunHuanYouXu2_R(vector<int>& datas, int findData, int frompos, int topos)
{
	if(frompos>topos)
		return -1;
	int mid = frompos + (topos-frompos) >> 1;
	if(datas[mid] == findData)
		return mid;
	
	if(frompos>=topos)
		return -1;

	int index = SearchBinaryXunHuanYouXu2_R(datas, findData, frompos, mid-1);
	if(index == -1)
	{
		index = SearchBinaryXunHuanYouXu2_R(datas, findData, mid+1, topos);
	}
 	return -1;
}

int Search::SearchBinaryXunHuanYouXu2(vector<int>& datas, int findData)
{
	
	return SearchBinaryXunHuanYouXu2_R(datas, findData, 0, datas.size()-1);
}