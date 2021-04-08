#pragma once
#include <vector>
using namespace std;

class Search
{
public:
	static int SearchBinary(vector<int>& datas, int findData);

	static int SearchBinaryFirst(vector<int>& datas, int findData);
	static int SearchBinaryLast(vector<int>& datas, int findData);

	static int SearchBinaryFirstGE(vector<int>& datas, int findData);
	static int SearchBinaryLastLE(vector<int>& datas, int findData);

	static int SearchBinaryXunHuanYouXu(vector<int>& datas, int findData);
	static int SearchBinaryXunHuanYouXu2(vector<int>& datas, int findData);
};