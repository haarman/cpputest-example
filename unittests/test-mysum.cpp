#include "CppUTest/TestHarness.h"

extern "C" {
  #include "../src/my_sum.h"
}

TEST_GROUP(TestMySum)
{
};

TEST(TestMySum, Test_MySumBasic) {
  LONGS_EQUAL(7, my_sum(3, 4));
}