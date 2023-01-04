#include <gtest/gtest.h>
#include "MyStack.h"

using namespace std;

TEST(MyStackSuite, frontStackAWithMultipleElements){
    vector<int> la = {1, 2, 3, 4, 5};
    MyStack mystack;
    mystack.setStackA(la);
    ASSERT_EQ(1, mystack.front_a());
}

TEST(MyStackSuite, frontStackAWithOneElement){
    vector<int> la = {1};
    MyStack mystack;
    mystack.setStackA(la);
    ASSERT_EQ(1, mystack.front_a());
}

TEST(MyStackSuite, frontStackAWithNoneElement){
    vector<int> la = {};
    MyStack mystack;
    mystack.setStackA(la);
    EXPECT_THROW(mystack.front_a(), EmptyStackException);
}

TEST(MyStackSuite, frontStackBWithMultipleElements){
    vector<int> lb = {1, 2, 3, 4, 5};
    MyStack mystack;
    mystack.setStackB(lb);
    ASSERT_EQ(1, mystack.front_b());
}

TEST(MyStackSuite, frontStackBWithOneElement){
    vector<int> lb = {1};
    MyStack mystack;
    mystack.setStackB(lb);
    ASSERT_EQ(1, mystack.front_b());
}

TEST(MyStackSuite, frontStackBWithNoneElement){
    vector<int> lb = {};
    MyStack mystack;
    mystack.setStackB(lb);
    EXPECT_THROW(mystack.front_b(), EmptyStackException);
}

TEST(MyStackSuite, backStackAWithMultipleElements){
    vector<int> la = {1, 2, 3, 4, 5};
    MyStack mystack;
    mystack.setStackA(la);
    ASSERT_EQ(5, mystack.back_a());
}

TEST(MyStackSuite, backStackAWithOneElement){
    vector<int> la = {1};
    MyStack mystack;
    mystack.setStackA(la);
    ASSERT_EQ(1, mystack.back_a());
}

TEST(MyStackSuite, backStackAWithNoneElement){
    vector<int> la = {};
    MyStack mystack;
    mystack.setStackA(la);
    EXPECT_THROW(mystack.back_a(), EmptyStackException);
}

TEST(MyStackSuite, backStackBWithMultipleElements){
    vector<int> lb = {1, 2, 3, 4, 5};
    MyStack mystack;
    mystack.setStackB(lb);
    ASSERT_EQ(5, mystack.back_b());
}

TEST(MyStackSuite, backStackBWithOneElement){
    vector<int> lb = {1};
    MyStack mystack;
    mystack.setStackB(lb);
    ASSERT_EQ(1, mystack.back_b());
}

TEST(MyStackSuite, backStackBWithNoneElement){
    vector<int> lb = {};
    MyStack mystack;
    mystack.setStackB(lb);
    EXPECT_THROW(mystack.back_b(), EmptyStackException);
}

TEST(MyStackSuite, saWithMultipleElements){
    vector<int> la = {1, 2, 3, 4, 5};
    MyStack mystack;
    mystack.setStackA(la);
    mystack.sa();
    vector<int> expected = {2, 1, 3, 4, 5};
    ASSERT_EQ(expected, mystack.getStackA());
}

TEST(MyStackSuite, saWithOneElement){
    vector<int> la = {2};
    MyStack mystack;
    mystack.setStackA(la);
    mystack.sa();
    vector<int> expected = {2};
    ASSERT_EQ(expected, mystack.getStackA());
}

TEST(MyStackSuite, saWithNoneElement){
    vector<int> la = {};
    MyStack mystack;
    mystack.setStackA(la);
    EXPECT_THROW(mystack.sa(), EmptyStackException);
}

TEST(MyStackSuite, sbWithMultipleElements){
    vector<int> lb = {1, 2, 3, 4, 5};
    MyStack mystack;
    mystack.setStackB(lb);
    mystack.sb();
    vector<int> expected = {2, 1, 3, 4, 5};
    ASSERT_EQ(expected, mystack.getStackB());
}

TEST(MyStackSuite, sbWithOneElement){
    vector<int> lb = {2};
    MyStack mystack;
    mystack.setStackB(lb);
    mystack.sb();
    vector<int> expected = {2};
    ASSERT_EQ(expected, mystack.getStackB());
}

TEST(MyStackSuite, sbWithNoneElement){
    vector<int> lb = {};
    MyStack mystack;
    mystack.setStackB(lb);
    EXPECT_THROW(mystack.sb(), EmptyStackException);
}

TEST(MyStackSuite, paWithMultipleElements){
    vector<int> la = {1, 2, 3, 4, 5};
    vector<int> lb = {6, 7, 8, 9, 10};
    MyStack mystack;
    mystack.setStackA(la);
    mystack.setStackB(lb);
    mystack.pa();
    vector<int> expectedA = {2, 3, 4, 5};
    vector<int> expectedB = {1, 6, 7, 8, 9, 10};
    ASSERT_EQ(expectedA, mystack.getStackA());
    ASSERT_EQ(expectedB, mystack.getStackB());
}

TEST(MyStackSuite, paWithMultipleElementsStackAandEmptyStackB){
    vector<int> la = {1, 2, 3, 4, 5};
    vector<int> lb = {};
    MyStack mystack;
    mystack.setStackA(la);
    mystack.setStackB(lb);
    mystack.pa();
    vector<int> expectedA = {2, 3, 4, 5};
    vector<int> expectedB = {1};
    ASSERT_EQ(expectedA, mystack.getStackA());
    ASSERT_EQ(expectedB, mystack.getStackB());
}

TEST(MyStackSuite, paWithOneElementStackAandEmptyStackB){
    vector<int> la = {1};
    vector<int> lb = {};
    MyStack mystack;
    mystack.setStackA(la);
    mystack.setStackB(lb);
    mystack.pa();
    vector<int> expectedA = {};
    vector<int> expectedB = {1};
    ASSERT_EQ(expectedA, mystack.getStackA());
    ASSERT_EQ(expectedB, mystack.getStackB());
}

TEST(MyStackSuite, paWithEmptyStackA){
    vector<int> la = {};
    MyStack mystack;
    mystack.setStackA(la);
    EXPECT_THROW(mystack.pa(), EmptyStackException);
}

TEST(MyStackSuite, pbWithMultipleElements){
    vector<int> lb = {1, 2, 3, 4, 5};
    vector<int> la = {6, 7, 8, 9, 10};
    MyStack mystack;
    mystack.setStackA(la);
    mystack.setStackB(lb);
    mystack.pb();
    vector<int> expectedB = {2, 3, 4, 5};
    vector<int> expectedA = {1, 6, 7, 8, 9, 10};
    ASSERT_EQ(expectedA, mystack.getStackA());
    ASSERT_EQ(expectedB, mystack.getStackB());
}

TEST(MyStackSuite, pbWithMultipleElementsStackBandEmptyStackA){
    vector<int> lb = {1, 2, 3, 4, 5};
    vector<int> la = {};
    MyStack mystack;
    mystack.setStackA(la);
    mystack.setStackB(lb);
    mystack.pb();
    vector<int> expectedB = {2, 3, 4, 5};
    vector<int> expectedA = {1};
    ASSERT_EQ(expectedA, mystack.getStackA());
    ASSERT_EQ(expectedB, mystack.getStackB());
}

TEST(MyStackSuite, pbWithOneElementStackBandEmptyStackA){
    vector<int> lb = {1};
    vector<int> la = {};
    MyStack mystack;
    mystack.setStackA(la);
    mystack.setStackB(lb);
    mystack.pb();
    vector<int> expectedB = {};
    vector<int> expectedA = {1};
    ASSERT_EQ(expectedA, mystack.getStackA());
    ASSERT_EQ(expectedB, mystack.getStackB());
}

TEST(MyStackSuite, pbWithEmptyStackB){
    vector<int> lb = {};
    MyStack mystack;
    mystack.setStackB(lb);
    EXPECT_THROW(mystack.pb(), EmptyStackException);
}

TEST(MyStackSuite, raWithMultipleElements){
    vector<int> la = {1, 2, 3, 4, 5};
    MyStack mystack;
    mystack.setStackA(la);
    mystack.ra();
    vector<int> expected = {2, 3, 4, 5, 1};
    ASSERT_EQ(expected, mystack.getStackA());
}

TEST(MyStackSuite, raWithOneElement){
    vector<int> la = {1};
    MyStack mystack;
    mystack.setStackA(la);
    EXPECT_THROW(mystack.ra(), LackStackElementException);
}

TEST(MyStackSuite, raWithNoneElement){
    vector<int> la = {};
    MyStack mystack;
    mystack.setStackA(la);
    EXPECT_THROW(mystack.ra(), EmptyStackException);
}

TEST(MyStackSuite, rbWithMultipleElements){
    vector<int> lb = {1, 2, 3, 4, 5};
    MyStack mystack;
    mystack.setStackB(lb);
    mystack.rb();
    vector<int> expected = {2, 3, 4, 5, 1};
    ASSERT_EQ(expected, mystack.getStackB());
}

TEST(MyStackSuite, rbWithOneElement){
    vector<int> lb = {1};
    MyStack mystack;
    mystack.setStackB(lb);
    EXPECT_THROW(mystack.rb(), LackStackElementException);
}

TEST(MyStackSuite, rbWithNoneElement){
    vector<int> lb = {};
    MyStack mystack;
    mystack.setStackB(lb);
    EXPECT_THROW(mystack.rb(), EmptyStackException);
}

TEST(MyStackSuite, rraWithMultipleElements){
    vector<int> la = {1, 2, 3, 4, 5};
    MyStack mystack;
    mystack.setStackA(la);
    mystack.rra();
    vector<int> expected = {5, 1, 2, 3, 4};
    ASSERT_EQ(expected, mystack.getStackA());
}

TEST(MyStackSuite, rraWithOneElement){
    vector<int> la = {1};
    MyStack mystack;
    mystack.setStackA(la);
    EXPECT_THROW(mystack.rra(), LackStackElementException);
}

TEST(MyStackSuite, rraWithNoneElement){
    vector<int> la = {};
    MyStack mystack;
    mystack.setStackA(la);
    EXPECT_THROW(mystack.rra(), EmptyStackException);
}

TEST(MyStackSuite, rrbWithMultipleElements){
    vector<int> lb = {1, 2, 3, 4, 5};
    MyStack mystack;
    mystack.setStackB(lb);
    mystack.rrb();
    vector<int> expected = {5, 1, 2, 3, 4};
    ASSERT_EQ(expected, mystack.getStackB());
}

TEST(MyStackSuite, rrbWithOneElement){
    vector<int> lb = {1};
    MyStack mystack;
    mystack.setStackB(lb);
    EXPECT_THROW(mystack.rrb(), LackStackElementException);
}

TEST(MyStackSuite, rrbWithNoneElement){
    vector<int> lb = {};
    MyStack mystack;
    mystack.setStackB(lb);
    EXPECT_THROW(mystack.rrb(), EmptyStackException);
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}