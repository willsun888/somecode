#include <ctime>
#include <iostream>
#include <string>
#include <vector>
//#include "external/com_google_googletest/googletest/include/gtest/gtest.h"
#include "gtest/gtest.h"
#include "main/hello-local.h"

TEST(local, test1)
{
    EXPECT_EQ(0, local("haha"));
}
