#include <gtest/gtest.h>
#include "MyStack.h"

TEST(MyStackSuite, frontStackAWithMultipleElements){
    MyStack mystack;
    mystack.setStackA({1, 2, 3, 4, 5});
    ASSERT_EQ(1, mystack.front_a());
}

TEST(MyStackSuite, frontStackAWithOneElement){
    MyStack mystack;
    mystack.setStackA({1});
    ASSERT_EQ(1, mystack.front_a());
}

TEST(MyStackSuite, frontStackAWithNoneElement){
    MyStack mystack;
    mystack.setStackA({});
    EXPECT_THROW(mystack.front_a(), EmptyStackException);
}

TEST(MyStackSuite, frontStackBWithMultipleElements){
    MyStack mystack;
    mystack.setStackB({1, 2, 3, 4, 5});
    ASSERT_EQ(1, mystack.front_b());
}

TEST(MyStackSuite, frontStackBWithOneElement){
    MyStack mystack;
    mystack.setStackB({1});
    ASSERT_EQ(1, mystack.front_b());
}

TEST(MyStackSuite, frontStackBWithNoneElement){
    MyStack mystack;
    mystack.setStackB({});
    EXPECT_THROW(mystack.front_b(), EmptyStackException);
}

TEST(MyStackSuite, backStackAWithMultipleElements){
    MyStack mystack;
    mystack.setStackA({1, 2, 3, 4, 5});
    ASSERT_EQ(5, mystack.back_a());
}

TEST(MyStackSuite, backStackAWithOneElement){
    MyStack mystack;
    mystack.setStackA({1});
    ASSERT_EQ(1, mystack.back_a());
}

TEST(MyStackSuite, backStackAWithNoneElement){
    MyStack mystack;
    mystack.setStackA({});
    EXPECT_THROW(mystack.back_a(), EmptyStackException);
}

TEST(MyStackSuite, backStackBWithMultipleElements){
    MyStack mystack;
    mystack.setStackB({1, 2, 3, 4, 5});
    ASSERT_EQ(5, mystack.back_b());
}

TEST(MyStackSuite, backStackBWithOneElement){
    MyStack mystack;
    mystack.setStackB({1});
    ASSERT_EQ(1, mystack.back_b());
}

TEST(MyStackSuite, backStackBWithNoneElement){
    MyStack mystack;
    mystack.setStackB({});
    EXPECT_THROW(mystack.back_b(), EmptyStackException);
}

TEST(MyStackSuite, saWithMultipleElements){
    MyStack mystack;
    mystack.setStackA({1, 2, 3, 4, 5});
    mystack.sa();
    list<int> expected = {2, 1, 3, 4, 5};
    ASSERT_EQ(expected, mystack.getStackA());
}

TEST(MyStackSuite, saWithOneElement){
    MyStack mystack;
    mystack.setStackA({2});
    mystack.sa();
    list<int> expected = {2};
    ASSERT_EQ(expected, mystack.getStackA());
}

TEST(MyStackSuite, saWithNoneElement){
    MyStack mystack;
    mystack.setStackA({});
    EXPECT_THROW(mystack.sa(), EmptyStackException);
}

TEST(MyStackSuite, sbWithMultipleElements){
    MyStack mystack;
    mystack.setStackB({1, 2, 3, 4, 5});
    mystack.sb();
    list<int> expected = {2, 1, 3, 4, 5};
    ASSERT_EQ(expected, mystack.getStackB());
}

TEST(MyStackSuite, sbWithOneElement){
    MyStack mystack;
    mystack.setStackB({2});
    mystack.sb();
    list<int> expected = {2};
    ASSERT_EQ(expected, mystack.getStackB());
}

TEST(MyStackSuite, sbWithNoneElement){
    MyStack mystack;
    mystack.setStackB({});
    EXPECT_THROW(mystack.sb(), EmptyStackException);
}

TEST(MyStackSuite, paWithMultipleElements){
    MyStack mystack;
    mystack.setStackA({1, 2, 3, 4, 5});
    mystack.setStackB({6, 7, 8, 9, 10});
    mystack.pa();
    list<int> expectedA = {2, 3, 4, 5};
    list<int> expectedB = {1, 6, 7, 8, 9, 10};
    ASSERT_EQ(expectedA, mystack.getStackA());
    ASSERT_EQ(expectedB, mystack.getStackB());
}

TEST(MyStackSuite, paWithMultipleElementsStackAandEmptyStackB){
    MyStack mystack;
    mystack.setStackA({1, 2, 3, 4, 5});
    mystack.setStackB({});
    mystack.pa();
    list<int> expectedA = {2, 3, 4, 5};
    list<int> expectedB = {1};
    ASSERT_EQ(expectedA, mystack.getStackA());
    ASSERT_EQ(expectedB, mystack.getStackB());
}

TEST(MyStackSuite, paWithOneElementStackAandEmptyStackB){
    MyStack mystack;
    mystack.setStackA({1});
    mystack.setStackB({});
    mystack.pa();
    list<int> expectedA = {};
    list<int> expectedB = {1};
    ASSERT_EQ(expectedA, mystack.getStackA());
    ASSERT_EQ(expectedB, mystack.getStackB());
}

TEST(MyStackSuite, paWithEmptyStackA){
    MyStack mystack;
    mystack.setStackA({});
    EXPECT_THROW(mystack.pa(), EmptyStackException);
}

TEST(MyStackSuite, pbWithMultipleElements){
    MyStack mystack;
    mystack.setStackA({6, 7, 8, 9, 10});
    mystack.setStackB({1, 2, 3, 4, 5});
    mystack.pb();
    list<int> expectedB = {2, 3, 4, 5};
    list<int> expectedA = {1, 6, 7, 8, 9, 10};
    ASSERT_EQ(expectedA, mystack.getStackA());
    ASSERT_EQ(expectedB, mystack.getStackB());
}

TEST(MyStackSuite, pbWithMultipleElementsStackBandEmptyStackA){
    MyStack mystack;
    mystack.setStackA({});
    mystack.setStackB({1, 2, 3, 4, 5});
    mystack.pb();
    list<int> expectedB = {2, 3, 4, 5};
    list<int> expectedA = {1};
    ASSERT_EQ(expectedA, mystack.getStackA());
    ASSERT_EQ(expectedB, mystack.getStackB());
}

TEST(MyStackSuite, pbWithOneElementStackBandEmptyStackA){
    MyStack mystack;
    mystack.setStackA({});
    mystack.setStackB({1});
    mystack.pb();
    list<int> expectedB = {};
    list<int> expectedA = {1};
    ASSERT_EQ(expectedA, mystack.getStackA());
    ASSERT_EQ(expectedB, mystack.getStackB());
}

TEST(MyStackSuite, pbWithEmptyStackB){
    MyStack mystack;
    mystack.setStackB({});
    EXPECT_THROW(mystack.pb(), EmptyStackException);
}

TEST(MyStackSuite, raWithMultipleElements){
    MyStack mystack;
    mystack.setStackA({1, 2, 3, 4, 5});
    mystack.ra();
    list<int> expected = {2, 3, 4, 5, 1};
    ASSERT_EQ(expected, mystack.getStackA());
}

TEST(MyStackSuite, raWithOneElement){
    MyStack mystack;
    mystack.setStackA({1});
    EXPECT_THROW(mystack.ra(), LackStackElementException);
}

TEST(MyStackSuite, raWithNoneElement){
    MyStack mystack;
    mystack.setStackA({});
    EXPECT_THROW(mystack.ra(), EmptyStackException);
}

TEST(MyStackSuite, rbWithMultipleElements){
    MyStack mystack;
    mystack.setStackB({1, 2, 3, 4, 5});
    mystack.rb();
    list<int> expected = {2, 3, 4, 5, 1};
    ASSERT_EQ(expected, mystack.getStackB());
}

TEST(MyStackSuite, rbWithOneElement){
    MyStack mystack;
    mystack.setStackB({1});
    EXPECT_THROW(mystack.rb(), LackStackElementException);
}

TEST(MyStackSuite, rbWithNoneElement){
    MyStack mystack;
    mystack.setStackB({});
    EXPECT_THROW(mystack.rb(), EmptyStackException);
}

TEST(MyStackSuite, rraWithMultipleElements){
    MyStack mystack;
    mystack.setStackA({1, 2, 3, 4, 5});
    mystack.rra();
    list<int> expected = {5, 1, 2, 3, 4};
    ASSERT_EQ(expected, mystack.getStackA());
}

TEST(MyStackSuite, rraWithOneElement){
    MyStack mystack;
    mystack.setStackA({1});
    EXPECT_THROW(mystack.rra(), LackStackElementException);
}

TEST(MyStackSuite, rraWithNoneElement){
    MyStack mystack;
    mystack.setStackA({});
    EXPECT_THROW(mystack.rra(), EmptyStackException);
}

TEST(MyStackSuite, rrbWithMultipleElements){
    MyStack mystack;
    mystack.setStackB({1, 2, 3, 4, 5});
    mystack.rrb();
    list<int> expected = {5, 1, 2, 3, 4};
    ASSERT_EQ(expected, mystack.getStackB());
}

TEST(MyStackSuite, rrbWithOneElement){
    MyStack mystack;
    mystack.setStackB({1});
    EXPECT_THROW(mystack.rrb(), LackStackElementException);
}

TEST(MyStackSuite, rrbWithNoneElement){
    MyStack mystack;
    mystack.setStackB({});
    EXPECT_THROW(mystack.rrb(), EmptyStackException);
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}