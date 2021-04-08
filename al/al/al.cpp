// al.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Test.h"
#include <windows.h>
#include <time.h>

#include "glog/GLogTool.h"

using namespace google;

#ifndef _TEST
int main(int argc, char* argv[])
{
	GLogTool::InitGLog();
	FuncMain::Instance()->RunTests();
	srand((unsigned int)time(NULL));

	int i1 = 0, i2 = 0, i3 = 0;
	auto b = i1 == i2 == i3;

	while (true)
	{
		int randnum = rand() % 3;
		if (randnum == 0)
		{
			LOG(INFO) << "testInfo " << randnum << endl;
		}
		else if (randnum == 1)
		{
			LOG(ERROR) << "testError " << randnum << endl;
		}
	}
	return 0;
}
#else
#include <gtest/gtest.h>
#include "glog/GTestTool.h"

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	return 0;
}
#endif

