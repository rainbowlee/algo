#include "Test.h"
#include <queue>

#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;
//漏斗限流
void LeakeyBucket()
{
	vector<int> va(10,0);

}

//令牌限流
void TokenBucket()
{

}
//布隆过滤器，对命中拦截，防止压力到mysql
void BloomFilter()
{

}


class QueueItem
{
public:
	int value;//值
	int index;//数组index
	int belong;//所属数组
};


struct compare
{
	bool Compare(const QueueItem& left, const QueueItem& right)
	{
		return false;
	}
};

struct compare1
{
	bool Compare1(const QueueItem& left, const QueueItem& right)
	{
		return false;
	}
};

struct cmp
{ //这个比较要用结构体表示
	bool operator()(QueueItem &a, QueueItem &b) const
	{
		return a.value > b.value;
	}
};


void AddItems(priority_queue<QueueItem, vector<QueueItem>, cmp>& priortyque, vector<int>& array, int belong, int index)
{
	if (array.size() > index)
	{
		QueueItem queueitem;
		queueitem.belong = belong;
		queueitem.index = index;
		queueitem.value = array[index];
		priortyque.push(queueitem);
	}
}

void MergeKVector()
{
	priority_queue<QueueItem,vector<QueueItem>, cmp> priortyque;

	vector<int> a = { 1,5,7,10 };
	vector<int> b = { 2,4,8,12 };
	vector<int> c = { 3,6,9,11 };


	vector<int> results;
	AddItems(priortyque, a, 0, 0);
	AddItems(priortyque, b, 1, 0);
	AddItems(priortyque, c, 2, 0);
	
	while (priortyque.size() > 0)
	{
		QueueItem queueItem = priortyque.top();
		priortyque.pop();
		
		results.push_back(queueItem.value);

		if (queueItem.belong == 0)
		{
			queueItem.index++;
			if (a.size() > queueItem.index)
			{
				queueItem.value = a[queueItem.index];
				priortyque.push(queueItem);
			}
		}

		if (queueItem.belong == 1)
		{
			queueItem.index++;
			if (b.size() > queueItem.index)
			{
				queueItem.value = b[queueItem.index];
				priortyque.push(queueItem);
			}
		}

		if (queueItem.belong == 2)
		{
			queueItem.index++;
			if (c.size() > queueItem.index)
			{
				queueItem.value = c[queueItem.index];
				priortyque.push(queueItem);
			}
		}
	}
}


typedef pair<string, int> Record;

//升序
struct RecordComparer {
	bool operator() (const Record &r1, const Record &r2) {
		return r1.second > r2.second;
	}
};

vector<Record> TopKNumbers(vector<string> &input, int k) {
	unordered_map<string, int> stat;
	for (const string &s : input) stat[s]++;
	priority_queue<Record, vector<Record>, RecordComparer> heap;
	auto iter = stat.begin();
	for (int i = 0; i < k && iter != stat.end(); i++, iter++) {
		heap.push(*iter);
	}
	for (; iter != stat.end(); iter++) {
		if (iter->second > heap.top().second) {
			heap.pop();
			heap.push(*iter);
		}
	}
	vector<Record> result;
	while (!heap.empty()) {
		result.push_back(heap.top());
		heap.pop();
	}
	return result;
}

void TestTopKFrequent() {
	vector<string> test;
	char buf[20];
	for (int i = 0; i < 100; i++) {
		int x = rand() % 20;
		//sprintf(buf, "STR%d", x);
		string str = "STR" + std::to_string(x);
		test.push_back(str);
	}
	cout << "what is a fuck" << endl;
	auto result = TopKNumbers(test, 5);
	for (auto it = result.rbegin(); it != result.rend(); it++) 
	{
		cout << it->first << "\t" << it->second << endl;
	}
	printf("============================\n");
	sort(test.begin(), test.end());
	for (const string s : test) {
		cout << s << endl;
	}
}

class TESTX
{
public:
	TESTX()
	{
		Register();
	}


	void Register()
	{
		FuncMain::Instance()->AddMethod(LeakeyBucket);
		FuncMain::Instance()->AddMethod(TokenBucket);
		FuncMain::Instance()->AddMethod(BloomFilter);
		FuncMain::Instance()->AddMethod(MergeKVector);
		FuncMain::Instance()->AddMethod(TestTopKFrequent);
	}
};

static TESTX a;