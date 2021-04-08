#include "Stack.h"
#include "Test.h"
#include <iostream>

void TestStack()
{
	Stack stack;
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);

	std::cout << stack.ToString() << std::endl;
	stack.Pop();
	std::cout << stack.ToString() << std::endl;
	stack.Pop();
	std::cout << stack.ToString() << std::endl;
	stack.Pop();
	std::cout << stack.ToString() << std::endl;

	stack.Pop();
	std::cout << stack.ToString() << std::endl;
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	std::cout << stack.ToString() << std::endl;
}



int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int muti(int a, int b)
{
	return a*b;
}

int divide(int a, int b)
{
	return a/b;
}

typedef int ( __cdecl *expressfunc)(int a, int b);

expressfunc GetFunc(char op)
{
	if(op == '+')
		return add;//return reinterpret_cast<expressfunc>(add);
	if(op == '-')
		return sub;//return reinterpret_cast<expressfunc>(sub);
	if(op == '*')
		return muti;//return reinterpret_cast<expressfunc>(muti);
	if(op == '/')
		return divide;//return reinterpret_cast<expressfunc>(divide);
	return nullptr;
}

bool DoActionFirst(char op, char cmp)
{
	int value1 = 0;
	int value2 = 0;
	switch (op)
	{
	case  '+':
	case '_':
		value1 = 1;
		break;
	case  '*':
	case '/':
		value1 = 2;
		break;
	default:
		break;
	}

	switch (cmp)
	{
	case  '+':
	case '_':
		value2 = 1;
		break;
	case  '*':
	case '/':
		value2 = 2;
		break;
	default:
		break;
	}

	return value1 >= value2;
}

int Expression(string str)
{
	Stack stackOp;
	Stack stackNum;

	bool inputError = false;
	for(int i = 0; i < str.size(); i++)
	{
		char c = str[i];
		std::cout << c <<endl;
		if(c >= '0' && c <='9')
		{
			if(i == str.size()-1)
			{
				//代码遗漏
				stackNum.Push(c-'0');
				//做一次从右到做的运算
				while(stackOp.Count() > 0)
				{
					int value;
					stackOp.Top(value);
					char op = static_cast<char>(value);

					if(stackNum.Count() < 2)
					{
						inputError = true;
						std::cout << "input error \r\n";
						break;
					}
					stackOp.Pop();

					int value1;
					stackNum.Top(value1);
					stackNum.Pop();
					int value2;
					stackNum.Top(value2);
					stackNum.Pop();

					expressfunc func = GetFunc(op);
					int result = func(value2, value1);//运算顺序
					stackNum.Push(result);
				}


				//下面是第一次写的代码， 存在漏洞 优先级高的在最后就有问题啦
				//if(stackOp.Count() != 1)
				//{
				//	inputError = true;
				//	std::cout << "input error \r\n";
				//	break;
				//}
				//int value = 0;
				//stackOp.Top(value);
				//stackOp.Pop();
				//char op = static_cast<char>(value);
				//expressfunc func = GetFunc(op);

				//if(stackNum.Count() != 1)
				//{
				//	inputError = true;
				//	std::cout << "input error \r\n";
				//	break;
				//}

				//int numvalue;
				//stackNum.Top(numvalue);
				//stackNum.Pop();

				//return (*func)(c, (char)numvalue);
			}
			else
			{
				stackNum.Push(c-'0');
			}
		}
		else if( c == '+' || c == '-' || c == '*' || c == '/' )
		{
			int count = stackOp.Count();
			if(count > 0)
			{
				int value;
				stackOp.Top(value);
				char op = static_cast<char>(value);
		
				bool cmpResult = DoActionFirst(op, c);
				if(cmpResult == true)
				{
					if(stackNum.Count() < 2)
					{
						inputError = true;
						std::cout << "input error \r\n";
						break;
					}
					stackOp.Pop();

					int value1;
					stackNum.Top(value1);
					stackNum.Pop();
					int value2;
					stackNum.Top(value2);
					stackNum.Pop();

					expressfunc func = GetFunc(op);
					int result = func(value2, value1);//运算顺序
					stackNum.Push(result);
					stackOp.Push(c);
				}
				else
				{
					stackOp.Push(c);
				}
			}
			else
			{
				stackOp.Push(c);
			}
		}
		else
		{
			inputError = true;
			std::cout << "input error \r\n";
			break;
		}
	}

	//结果返回
	int result = 0;
	stackNum.Top(result);
	stackNum.Pop();
	return result;
}

//表达式实现 四则运算 + - */ eg:a + b + c*d*f
void TestExpression1()
{
	string str = "1+2+5*4";
	int result = Expression(str);

	std::cout << "TestExpression1 " << result << endl ;
}

void TestExpression2()
{
	string str = "4/5+1+2+5*4";
	int result = Expression(str);

	std::cout << "TestExpression2 " << result << endl ;
}

static bool Macth(string str)
{
	Stack stack;

	bool inputerror = false;
	for(int i = 0; i < str.size(); i++)
	{
		char c = str[i];
		if( c == '[' || c == '{' )
		{
			stack.Push(c);
		} 
		else if(c == ']' || c == '}')
		{
			if(stack.Count() <= 0)
				return false;
			int value;
			stack.Top(value);
			char ccmp = static_cast<char>(value);
			if(c== ']' && ccmp == '[')
			{
				stack.Pop();
			}
			else if(c== '}' && ccmp == '{' )
			{
				stack.Pop();
			}
			else
			{
				return false;
			}
		}
		else
		{
			inputerror = true;
			break;
		}
		
	}

	return stack.Count() == 0;
}

//括号匹配 {}[]
void TestMath1()
{
	string str = "{[{[[]]}]}";
	bool matched = Macth(str);
	if(matched)
		std::cout << "TestMath1 matched " << endl;
	else
		std::cout << "TestMath1 match error" << endl;
}


void TestMath2()
{
	string str = "{[}]";
	bool matched = Macth(str);
	if(matched)
		std::cout << "TestMath1 matched " << endl;
	else
		std::cout << "TestMath1 match error" << endl;
}


//重做，取消
void TestDoRedoList()
{

}

class TESTStack
{
public:
	TESTStack()
	{
		Register();
	}


	void Register()
	{
		FuncMain::Instance()->AddMethod(TestStack);
		FuncMain::Instance()->AddMethod(TestExpression1);
		FuncMain::Instance()->AddMethod(TestExpression2);
		FuncMain::Instance()->AddMethod(TestMath1);
		FuncMain::Instance()->AddMethod(TestMath2);
		FuncMain::Instance()->AddMethod(TestDoRedoList);
	}
};

static TESTStack a;