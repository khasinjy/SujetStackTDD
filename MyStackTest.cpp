#include <gtest/gtest.h>
#include "MyStack.h"

using namespace std;

TEST(MyStackSuite, frontStackAWithMultipleElements){
    list<int> la = {1, 2, 3, 4, 5};
    MyStack mystack;
    mystack.setStackA(la);
    ASSERT_EQ(1, mystack.front_a());
}

TEST(MyStackSuite, frontStackAWithOneElement){
    list<int> la = {1};
    MyStack mystack;
    mystack.setStackA(la);
    ASSERT_EQ(1, mystack.front_a());
}

TEST(MyStackSuite, frontStackAWithNoneElement){
    list<int> la = {};
    MyStack mystack;
    mystack.setStackA(la);
    EXPECT_THROW(mystack.front_a(), EmptyStackException);
}

TEST(MyStackSuite, frontStackBWithMultipleElements){
    list<int> lb = {1, 2, 3, 4, 5};
    MyStack mystack;
    mystack.setStackB(lb);
    ASSERT_EQ(1, mystack.front_b());
}

TEST(MyStackSuite, frontStackBWithOneElement){
    list<int> lb = {1};
    MyStack mystack;
    mystack.setStackB(lb);
    ASSERT_EQ(1, mystack.front_b());
}

TEST(MyStackSuite, frontStackBWithNoneElement){
    list<int> lb = {};
    MyStack mystack;
    mystack.setStackB(lb);
    EXPECT_THROW(mystack.front_b(), EmptyStackException);
}

TEST(MyStackSuite, backStackAWithMultipleElements){
    list<int> la = {1, 2, 3, 4, 5};
    MyStack mystack;
    mystack.setStackA(la);
    ASSERT_EQ(5, mystack.back_a());
}

TEST(MyStackSuite, backStackAWithOneElement){
    list<int> la = {1};
    MyStack mystack;
    mystack.setStackA(la);
    ASSERT_EQ(1, mystack.back_a());
}

TEST(MyStackSuite, backStackAWithNoneElement){
    list<int> la = {};
    MyStack mystack;
    mystack.setStackA(la);
    EXPECT_THROW(mystack.back_a(), EmptyStackException);
}

TEST(MyStackSuite, backStackBWithMultipleElements){
    list<int> lb = {1, 2, 3, 4, 5};
    MyStack mystack;
    mystack.setStackB(lb);
    ASSERT_EQ(5, mystack.back_b());
}

TEST(MyStackSuite, backStackBWithOneElement){
    list<int> lb = {1};
    MyStack mystack;
    mystack.setStackB(lb);
    ASSERT_EQ(1, mystack.back_b());
}

TEST(MyStackSuite, backStackBWithNoneElement){
    list<int> lb = {};
    MyStack mystack;
    mystack.setStackB(lb);
    EXPECT_THROW(mystack.back_b(), EmptyStackException);
}

TEST(MyStackSuite, saWithMultipleElements){
    list<int> la = {1, 2, 3, 4, 5};
    MyStack mystack;
    mystack.setStackA(la);
    mystack.sa();
    list<int> expected = {2, 1, 3, 4, 5};
    ASSERT_EQ(expected, mystack.getStackA());
}

TEST(MyStackSuite, saWithOneElement){
    list<int> la = {2};
    MyStack mystack;
    mystack.setStackA(la);
    mystack.sa();
    list<int> expected = {2};
    ASSERT_EQ(expected, mystack.getStackA());
}

TEST(MyStackSuite, saWithNoneElement){
    list<int> la = {};
    MyStack mystack;
    mystack.setStackA(la);
    EXPECT_THROW(mystack.sa(), EmptyStackException);
}

TEST(MyStackSuite, sbWithMultipleElements){
    list<int> lb = {1, 2, 3, 4, 5};
    MyStack mystack;
    mystack.setStackB(lb);
    mystack.sb();
    list<int> expected = {2, 1, 3, 4, 5};
    ASSERT_EQ(expected, mystack.getStackB());
}

TEST(MyStackSuite, sbWithOneElement){
    list<int> lb = {2};
    MyStack mystack;
    mystack.setStackB(lb);
    mystack.sb();
    list<int> expected = {2};
    ASSERT_EQ(expected, mystack.getStackB());
}

TEST(MyStackSuite, sbWithNoneElement){
    list<int> lb = {};
    MyStack mystack;
    mystack.setStackB(lb);
    EXPECT_THROW(mystack.sb(), EmptyStackException);
}

TEST(MyStackSuite, paWithMultipleElements){
    list<int> la = {1, 2, 3, 4, 5};
    list<int> lb = {6, 7, 8, 9, 10};
    MyStack mystack;
    mystack.setStackA(la);
    mystack.setStackB(lb);
    mystack.pa();
    list<int> expectedA = {2, 3, 4, 5};
    list<int> expectedB = {1, 6, 7, 8, 9, 10};
    ASSERT_EQ(expectedA, mystack.getStackA());
    ASSERT_EQ(expectedB, mystack.getStackB());
}

TEST(MyStackSuite, paWithMultipleElementsStackAandEmptyStackB){
    list<int> la = {1, 2, 3, 4, 5};
    list<int> lb = {};
    MyStack mystack;
    mystack.setStackA(la);
    mystack.setStackB(lb);
    mystack.pa();
    list<int> expectedA = {2, 3, 4, 5};
    list<int> expectedB = {1};
    ASSERT_EQ(expectedA, mystack.getStackA());
    ASSERT_EQ(expectedB, mystack.getStackB());
}

TEST(MyStackSuite, paWithOneElementStackAandEmptyStackB){
    list<int> la = {1};
    list<int> lb = {};
    MyStack mystack;
    mystack.setStackA(la);
    mystack.setStackB(lb);
    mystack.pa();
    list<int> expectedA = {};
    list<int> expectedB = {1};
    ASSERT_EQ(expectedA, mystack.getStackA());
    ASSERT_EQ(expectedB, mystack.getStackB());
}

TEST(MyStackSuite, paWithEmptyStackA){
    list<int> la = {};
    MyStack mystack;
    mystack.setStackA(la);
    EXPECT_THROW(mystack.pa(), EmptyStackException);
}

TEST(MyStackSuite, pbWithMultipleElements){
    list<int> lb = {1, 2, 3, 4, 5};
    list<int> la = {6, 7, 8, 9, 10};
    MyStack mystack;
    mystack.setStackA(la);
    mystack.setStackB(lb);
    mystack.pb();
    list<int> expectedB = {2, 3, 4, 5};
    list<int> expectedA = {1, 6, 7, 8, 9, 10};
    ASSERT_EQ(expectedA, mystack.getStackA());
    ASSERT_EQ(expectedB, mystack.getStackB());
}

TEST(MyStackSuite, pbWithMultipleElementsStackBandEmptyStackA){
    list<int> lb = {1, 2, 3, 4, 5};
    list<int> la = {};
    MyStack mystack;
    mystack.setStackA(la);
    mystack.setStackB(lb);
    mystack.pb();
    list<int> expectedB = {2, 3, 4, 5};
    list<int> expectedA = {1};
    ASSERT_EQ(expectedA, mystack.getStackA());
    ASSERT_EQ(expectedB, mystack.getStackB());
}

TEST(MyStackSuite, pbWithOneElementStackBandEmptyStackA){
    list<int> lb = {1};
    list<int> la = {};
    MyStack mystack;
    mystack.setStackA(la);
    mystack.setStackB(lb);
    mystack.pb();
    list<int> expectedB = {};
    list<int> expectedA = {1};
    ASSERT_EQ(expectedA, mystack.getStackA());
    ASSERT_EQ(expectedB, mystack.getStackB());
}

TEST(MyStackSuite, pbWithEmptyStackB){
    list<int> lb = {};
    MyStack mystack;
    mystack.setStackB(lb);
    EXPECT_THROW(mystack.pb(), EmptyStackException);
}

TEST(MyStackSuite, raWithMultipleElements){
    list<int> la = {1, 2, 3, 4, 5};
    MyStack mystack;
    mystack.setStackA(la);
    mystack.ra();
    list<int> expected = {2, 3, 4, 5, 1};
    ASSERT_EQ(expected, mystack.getStackA());
}

TEST(MyStackSuite, raWithOneElement){
    list<int> la = {1};
    MyStack mystack;
    mystack.setStackA(la);
    EXPECT_THROW(mystack.ra(), LackStackElementException);
}

TEST(MyStackSuite, raWithNoneElement){
    list<int> la = {};
    MyStack mystack;
    mystack.setStackA(la);
    EXPECT_THROW(mystack.ra(), EmptyStackException);
}

TEST(MyStackSuite, rbWithMultipleElements){
    list<int> lb = {1, 2, 3, 4, 5};
    MyStack mystack;
    mystack.setStackB(lb);
    mystack.rb();
    list<int> expected = {2, 3, 4, 5, 1};
    ASSERT_EQ(expected, mystack.getStackB());
}

TEST(MyStackSuite, rbWithOneElement){
    list<int> lb = {1};
    MyStack mystack;
    mystack.setStackB(lb);
    EXPECT_THROW(mystack.rb(), LackStackElementException);
}

TEST(MyStackSuite, rbWithNoneElement){
    list<int> lb = {};
    MyStack mystack;
    mystack.setStackB(lb);
    EXPECT_THROW(mystack.rb(), EmptyStackException);
}

TEST(MyStackSuite, rraWithMultipleElements){
    list<int> la = {1, 2, 3, 4, 5};
    MyStack mystack;
    mystack.setStackA(la);
    mystack.rra();
    list<int> expected = {5, 1, 2, 3, 4};
    ASSERT_EQ(expected, mystack.getStackA());
}

TEST(MyStackSuite, rraWithOneElement){
    list<int> la = {1};
    MyStack mystack;
    mystack.setStackA(la);
    EXPECT_THROW(mystack.rra(), LackStackElementException);
}

TEST(MyStackSuite, rraWithNoneElement){
    list<int> la = {};
    MyStack mystack;
    mystack.setStackA(la);
    EXPECT_THROW(mystack.rra(), EmptyStackException);
}

TEST(MyStackSuite, rrbWithMultipleElements){
    list<int> lb = {1, 2, 3, 4, 5};
    MyStack mystack;
    mystack.setStackB(lb);
    mystack.rrb();
    list<int> expected = {5, 1, 2, 3, 4};
    ASSERT_EQ(expected, mystack.getStackB());
}

TEST(MyStackSuite, rrbWithOneElement){
    list<int> lb = {1};
    MyStack mystack;
    mystack.setStackB(lb);
    EXPECT_THROW(mystack.rrb(), LackStackElementException);
}

TEST(MyStackSuite, rrbWithNoneElement){
    list<int> lb = {};
    MyStack mystack;
    mystack.setStackB(lb);
    EXPECT_THROW(mystack.rrb(), EmptyStackException);
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}