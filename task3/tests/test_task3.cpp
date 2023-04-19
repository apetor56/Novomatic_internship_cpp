#include <gtest/gtest.h>
#include "task3.hpp"

TEST(Task3_test, test) {  
  EXPECT_EQ(function(' ', "    123456  789  "), "123456  789");
  EXPECT_EQ(function('0', "  00 123 00"), "  00 123 ");
  EXPECT_EQ(function('-', "-------"), "");
  EXPECT_EQ(function('a', "aaaaaabdef   a"), "bdef   ");
  EXPECT_EQ(function('x', "x!@#xxx"), "!@#");
  EXPECT_EQ(function('?', "?"), "");
}