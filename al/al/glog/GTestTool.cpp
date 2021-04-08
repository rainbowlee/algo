#include "GTestTool.h"
#include "../protobuf/DrdServerControl.pb.h"
#include <vector>
using namespace std;
class TestLink :public testing::Test
{
public:
	virtual void SetUp()
	{
	}
	virtual void TearDown()
	{
	}
};

TEST_F(TestLink, PushBack)
{
	int a = 2;
	ASSERT_FALSE(a == 2);
}


TEST(TestHello, Test)
{

	DdrRegisterDSServer registerDS;
	registerDS.set_dsid(1);

	string data = registerDS.SerializeAsString();
	DdrRegisterDSServer newRegisterDS;
	newRegisterDS.ParseFromString(data);

	int a = 2;
	ASSERT_FALSE(a == 2);
}