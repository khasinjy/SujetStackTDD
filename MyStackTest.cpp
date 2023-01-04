#include <gtest/gtest.h>
#include "MyStack.h"

TEST(frontStackA, withMultipleElements){
    MyStack mystack;
    mystack.setStackA({1, 2, 3, 4, 5});
    ASSERT_EQ(1, mystack.front_a());
}

TEST(frontStackA, withOneElement){
    MyStack mystack;
    mystack.setStackA({1});
    ASSERT_EQ(1, mystack.front_a());
}

TEST(frontStackA, withNoneElement){
    MyStack mystack;
    mystack.setStackA({});
    EXPECT_THROW(mystack.front_a(), EmptyStackException);
}

TEST(frontStackB, withMultipleElements){
    MyStack mystack;
    mystack.setStackB({1, 2, 3, 4, 5});
    ASSERT_EQ(1, mystack.front_b());
}

TEST(frontStackB, withOneElement){
    MyStack mystack;
    mystack.setStackB({1});
    ASSERT_EQ(1, mystack.front_b());
}

TEST(frontStackB, withNoneElement){
    MyStack mystack;
    mystack.setStackB({});
    EXPECT_THROW(mystack.front_b(), EmptyStackException);
}

TEST(backStackA, withMultipleElements){
    MyStack mystack;
    mystack.setStackA({1, 2, 3, 4, 5});
    ASSERT_EQ(5, mystack.back_a());
}

TEST(backStackA, withOneElement){
    MyStack mystack;
    mystack.setStackA({1});
    ASSERT_EQ(1, mystack.back_a());
}

TEST(backStackA, withNoneElement){
    MyStack mystack;
    mystack.setStackA({});
    EXPECT_THROW(mystack.back_a(), EmptyStackException);
}

TEST(backStackB, withMultipleElements){
    MyStack mystack;
    mystack.setStackB({1, 2, 3, 4, 5});
    ASSERT_EQ(5, mystack.back_b());
}

TEST(backStackB, withOneElement){
    MyStack mystack;
    mystack.setStackB({1});
    ASSERT_EQ(1, mystack.back_b());
}

TEST(backStackB, withNoneElement){
    MyStack mystack;
    mystack.setStackB({});
    EXPECT_THROW(mystack.back_b(), EmptyStackException);
}

TEST(sa, withMultipleElements){
    MyStack mystack;
    mystack.setStackA({1, 2, 3, 4, 5});
    mystack.sa();
    vector<int> expected = {2, 1, 3, 4, 5};
    ASSERT_EQ(expected, mystack.getStackA());
}

TEST(sa, withOneElement){
    MyStack mystack;
    mystack.setStackA({2});
    mystack.sa();
    vector<int> expected = {2};
    ASSERT_EQ(expected, mystack.getStackA());
}

TEST(sa, withNoneElement){
    MyStack mystack;
    mystack.setStackA({});
    EXPECT_THROW(mystack.sa(), EmptyStackException);
}

TEST(sb, withMultipleElements){
    MyStack mystack;
    mystack.setStackB({1, 2, 3, 4, 5});
    mystack.sb();
    vector<int> expected = {2, 1, 3, 4, 5};
    ASSERT_EQ(expected, mystack.getStackB());
}

TEST(sb, withOneElement){
    MyStack mystack;
    mystack.setStackB({2});
    mystack.sb();
    vector<int> expected = {2};
    ASSERT_EQ(expected, mystack.getStackB());
}

TEST(sb, withNoneElement){
    MyStack mystack;
    mystack.setStackB({});
    EXPECT_THROW(mystack.sb(), EmptyStackException);
}

TEST(pa, withMultipleElements){
    MyStack mystack;
    mystack.setStackA({1, 2, 3, 4, 5});
    mystack.setStackB({6, 7, 8, 9, 10});
    mystack.pa();
    vector<int> expectedA = {2, 3, 4, 5};
    vector<int> expectedB = {1, 6, 7, 8, 9, 10};
    ASSERT_EQ(expectedA, mystack.getStackA());
    ASSERT_EQ(expectedB, mystack.getStackB());
}

TEST(pa, withMultipleElementsStackAandEmptyStackB){
    MyStack mystack;
    mystack.setStackA({1, 2, 3, 4, 5});
    mystack.setStackB({});
    mystack.pa();
    vector<int> expectedA = {2, 3, 4, 5};
    vector<int> expectedB = {1};
    ASSERT_EQ(expectedA, mystack.getStackA());
    ASSERT_EQ(expectedB, mystack.getStackB());
}

TEST(pa, withOneElementStackAandEmptyStackB){
    MyStack mystack;
    mystack.setStackA({1});
    mystack.setStackB({});
    mystack.pa();
    vector<int> expectedA = {};
    vector<int> expectedB = {1};
    ASSERT_EQ(expectedA, mystack.getStackA());
    ASSERT_EQ(expectedB, mystack.getStackB());
}

TEST(pa, withEmptyStackA){
    MyStack mystack;
    mystack.setStackA({});
    EXPECT_THROW(mystack.pa(), EmptyStackException);
}

TEST(pb, withMultipleElements){
    MyStack mystack;
    mystack.setStackA({6, 7, 8, 9, 10});
    mystack.setStackB({1, 2, 3, 4, 5});
    mystack.pb();
    vector<int> expectedB = {2, 3, 4, 5};
    vector<int> expectedA = {1, 6, 7, 8, 9, 10};
    ASSERT_EQ(expectedA, mystack.getStackA());
    ASSERT_EQ(expectedB, mystack.getStackB());
}

TEST(pb, withMultipleElementsStackBandEmptyStackA){
    MyStack mystack;
    mystack.setStackA({});
    mystack.setStackB({1, 2, 3, 4, 5});
    mystack.pb();
    vector<int> expectedB = {2, 3, 4, 5};
    vector<int> expectedA = {1};
    ASSERT_EQ(expectedA, mystack.getStackA());
    ASSERT_EQ(expectedB, mystack.getStackB());
}

TEST(pb, withOneElementStackBandEmptyStackA){
    MyStack mystack;
    mystack.setStackA({});
    mystack.setStackB({1});
    mystack.pb();
    vector<int> expectedB = {};
    vector<int> expectedA = {1};
    ASSERT_EQ(expectedA, mystack.getStackA());
    ASSERT_EQ(expectedB, mystack.getStackB());
}

TEST(pb, withEmptyStackB){
    MyStack mystack;
    mystack.setStackB({});
    EXPECT_THROW(mystack.pb(), EmptyStackException);
}

TEST(ra, withMultipleElements){
    MyStack mystack;
    mystack.setStackA({1, 2, 3, 4, 5});
    mystack.ra();
    vector<int> expected = {2, 3, 4, 5, 1};
    ASSERT_EQ(expected, mystack.getStackA());
}

TEST(ra, withOneElement){
    MyStack mystack;
    mystack.setStackA({1});
    EXPECT_THROW(mystack.ra(), LackStackElementException);
}

TEST(ra, withNoneElement){
    MyStack mystack;
    mystack.setStackA({});
    EXPECT_THROW(mystack.ra(), EmptyStackException);
}

TEST(rb, withMultipleElements){
    MyStack mystack;
    mystack.setStackB({1, 2, 3, 4, 5});
    mystack.rb();
    vector<int> expected = {2, 3, 4, 5, 1};
    ASSERT_EQ(expected, mystack.getStackB());
}

TEST(rb, withOneElement){
    MyStack mystack;
    mystack.setStackB({1});
    EXPECT_THROW(mystack.rb(), LackStackElementException);
}

TEST(rb, withNoneElement){
    MyStack mystack;
    mystack.setStackB({});
    EXPECT_THROW(mystack.rb(), EmptyStackException);
}

TEST(rra, withMultipleElements){
    MyStack mystack;
    mystack.setStackA({1, 2, 3, 4, 5});
    mystack.rra();
    vector<int> expected = {5, 1, 2, 3, 4};
    ASSERT_EQ(expected, mystack.getStackA());
}

TEST(rra, withOneElement){
    MyStack mystack;
    mystack.setStackA({1});
    EXPECT_THROW(mystack.rra(), LackStackElementException);
}

TEST(rra, withNoneElement){
    MyStack mystack;
    mystack.setStackA({});
    EXPECT_THROW(mystack.rra(), EmptyStackException);
}

TEST(rrb, withMultipleElements){
    MyStack mystack;
    mystack.setStackB({1, 2, 3, 4, 5});
    mystack.rrb();
    vector<int> expected = {5, 1, 2, 3, 4};
    ASSERT_EQ(expected, mystack.getStackB());
}

TEST(rrb, withOneElement){
    MyStack mystack;
    mystack.setStackB({1});
    EXPECT_THROW(mystack.rrb(), LackStackElementException);
}

TEST(rrb, withNoneElement){
    MyStack mystack;
    mystack.setStackB({});
    EXPECT_THROW(mystack.rrb(), EmptyStackException);
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}