#include "mystring.h"
#include <gtest/gtest.h>

// Constructor Test
TEST(MyStringTest, Constructor) {
    char str[] = "Hello, World!";
    MyString myStr(str);
    EXPECT_EQ(myStr.ToString(), "Hello, World!");
}

// Destructor Test
// Destructor is implicitly tested through the lifecycle of other tests

// Length Test
TEST(MyStringTest, Length) {
    char str[] = "Hello";
    MyString myStr(str);
    EXPECT_EQ(myStr.length(), 5);
}

// ToString Test
TEST(MyStringTest, ToString) {
    char str[] = "Test String";
    MyString myStr(str);
    EXPECT_EQ(myStr.ToString(), "Test String");
}

// Substring Test
TEST(MyStringTest, Substr) {
    char str[] = "Hello, World!";
    MyString myStr(str);
    EXPECT_EQ(myStr.substr(0, 5).ToString(), "Hello");
    EXPECT_EQ(myStr.substr(7, 5).ToString(), "World");
    EXPECT_EQ(myStr.substr(7).ToString(), "World!"); // Test with default n = -1
}

// Addition Operator Test
TEST(MyStringTest, AdditionOperator) {
    char str1[] = "Hello, ";
    char str2[] = "World!";
    MyString myStr1(str1);
    MyString myStr2(str2);
    MyString result = myStr1 + myStr2;
    EXPECT_EQ(result.ToString(), "Hello, World!");
}

// Assignment Operator Test
TEST(MyStringTest, AssignmentOperator) {
    char str1[] = "Test";
    char str2[] = "Another";
    MyString myStr1(str1);
    MyString myStr2(str2);
    myStr1 = myStr2;
    EXPECT_EQ(myStr1.ToString(), "Another");
}

// Relational Operators Tests
TEST(MyStringTest, RelationalOperators) {
    char str1[] = "Apple";
    char str2[] = "Banana";
    MyString myStr1(str1);
    MyString myStr2(str2);

    EXPECT_TRUE(myStr1 < myStr2);
    EXPECT_FALSE(myStr2 < myStr1);
    EXPECT_TRUE(myStr2 > myStr1);
    EXPECT_FALSE(myStr1 > myStr2);
    EXPECT_TRUE(myStr1 <= myStr2);
    EXPECT_TRUE(myStr1 <= myStr1);
    EXPECT_TRUE(myStr2 >= myStr1);
    EXPECT_TRUE(myStr2 >= myStr2);
    EXPECT_FALSE(myStr1 == myStr2);
    EXPECT_TRUE(myStr1 != myStr2);
}

// Edge Case Tests
TEST(MyStringTest, EdgeCases) {
    char emptyStr[] = "";
    MyString emptyMyStr(emptyStr);
    EXPECT_EQ(emptyMyStr.length(), 0);
    EXPECT_EQ(emptyMyStr.ToString(), "");

    char oneCharStr[] = "A";
    MyString oneCharMyStr(oneCharStr);
    EXPECT_EQ(oneCharMyStr.length(), 1);
    EXPECT_EQ(oneCharMyStr.ToString(), "A");

    // Substring beyond length
    EXPECT_EQ(emptyMyStr.substr(0, 5).ToString(), "");
    EXPECT_EQ(oneCharMyStr.substr(1, 5).ToString(), "");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
