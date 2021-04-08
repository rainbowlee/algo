#include <memory>
#include <iostream>
#include <string>
using namespace std;
#include "C++11_Ptr.h"
#include "../Test.h"

class Bad : public enable_shared_from_this<Bad>//非public不成
{
public:
	void fun()
	{
		shared_ptr<Bad> sp(shared_from_this());
		cout<<sp.use_count()<<endl;
	}
};


class Person : public enable_shared_from_this<Person>
{
public:
	Person(const string& name)
		: m_name( name )
	{
	}

	~Person()
	{
		cout << "release " << m_name << endl;
	}

	string getName() const
	{
		return m_name;
	}

	void setFather(shared_ptr<Person> f)
	{
		m_father = f;
		if (f)
		{
			f->m_kids.push_back(shared_from_this());
		}
	}

	void setMother(shared_ptr<Person> m)
	{
		m_mother = m;
		if (m)
		{
			m->m_kids.push_back(shared_from_this());
		}
	}

	shared_ptr<Person> getKid(size_t idx)
	{
		if (idx < m_kids.size())
		{
			weak_ptr<Person> p = m_kids.at(idx);
			if (!p.expired())
			{
				return p.lock();
			}
		}
		return nullptr;
	}

private:
	string                        m_name;
	shared_ptr<Person>            m_father;
	shared_ptr<Person>            m_mother;
	//vector<shared_ptr<Person>>    m_kids; // 循环依赖
	vector<weak_ptr<Person>>      m_kids;
};



void Test1()
{
	cout << "Test_Ptr::Test1" << endl;
	shared_ptr<Bad> sp(make_shared<Bad>());
	sp->fun(); //输出为1
	cout << sp.use_count() << endl;
	weak_ptr<Bad> weakptr(sp);
	weak_ptr<Bad> weakptr2(weakptr);
	cout << sp.use_count() << endl;
	shared_ptr<Bad> sp2 = shared_ptr<Bad>(weakptr2);
	cout << sp.use_count() << endl;
}

void Test2()
{
	cout << "Test_Ptr::Test2" << endl;
	std::shared_ptr<int> sp(new int(10));
	std::weak_ptr<int> wp(sp);
	wp = sp;
	// 检查 weak_ptr 内部对象的合法性.
	if (std::shared_ptr<int> sp = wp.lock())
	{
		cout << " weak ptr lock"  << endl;
	}
	//printf("%d\n", wp.use_count()); // 1
	wp.reset();
	//printf("%d\n", wp); // 0

	// 检查 weak_ptr 内部对象的合法性.
	if (std::shared_ptr<int> sp = wp.lock())
	{
		cout << " weak ptr lock erro" << endl;
	}
}

void Test3()
{
	cout << "Test_Ptr::Test3" << endl;
	// 测试代码
	shared_ptr<Person> jack( make_shared<Person>("Jack") );
	shared_ptr<Person> lucy( make_shared<Person>("Lucy") );
	shared_ptr<Person> john( make_shared<Person>("John") );
	john->setFather(jack);
	john->setMother(lucy);

	auto p = jack->getKid(0);
	if (p)
	{
		cout << p->getName() << endl;
	}
}


class Test_Ptr
{
public:
	Test_Ptr()
	{
		Init();
	}

	void Init()
	{
		FuncMain::Instance()->AddMethod(Test1);
		FuncMain::Instance()->AddMethod(Test2);
		FuncMain::Instance()->AddMethod(Test3);
	}
};




static Test_Ptr a;