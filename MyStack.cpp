#include "MyStack.h"

MyStack::MyStack(){
    stack_a = {};
    stack_b = {};
}

vector<int> MyStack::getStackA(){
    return stack_a;
}

vector<int> MyStack::getStackB(){
    return stack_b;
}

void MyStack::setStackA(vector<int> stackA){
    stack_a = stackA;
}

void MyStack::setStackB(vector<int> stackB){
    stack_b = stackB;
}

int MyStack::internal_front(vector<int>& stack){
    if(stack.empty()) throw EmptyStackException();
    return stack.front();
}

int MyStack::front_a(){
    return internal_front(stack_a);
}

int MyStack::front_b(){
    return internal_front(stack_b);
}

int MyStack::internal_back(vector<int>& stack){
    if(stack.empty()) throw EmptyStackException();
    return stack.back();
}

int MyStack::back_a(){
    return internal_back(stack_a);
}

int MyStack::back_b(){
    return internal_back(stack_b);
}

void MyStack::internal_s(vector<int>& stack){
    if(stack.empty()) throw EmptyStackException();
    if(stack.size() == 1) return;
    auto firstIt = stack.begin();
    auto secondIt = next(firstIt, 1);
    iter_swap(firstIt, secondIt);
}

void MyStack::sa(){
    internal_s(stack_a);
}

void MyStack::sb(){
    internal_s(stack_b);
}

void MyStack::internal_p(vector<int>& stackSource, vector<int>& stackTarget){
    if(stackSource.empty()) throw EmptyStackException();
    int first = stackSource.front();
    stackSource.erase(stackSource.begin());
    stackTarget.insert(stackTarget.begin(), first);
}

void MyStack::pa(){
    internal_p(stack_a, stack_b);
}

void MyStack::pb(){
    internal_p(stack_b, stack_a);
}

void MyStack::internal_r(vector<int>& stack){
    if(stack.empty()) throw EmptyStackException();
    if(stack.size() == 1) throw LackStackElementException();
    int element = stack.front();
    stack.erase(stack.begin());
    stack.push_back(element);
}

void MyStack::ra(){
    internal_r(stack_a);
}

void MyStack::rb(){
    internal_r(stack_b);
}

void MyStack::internal_rr(vector<int>& stack){
    if(stack.empty()) throw EmptyStackException();
    if(stack.size() == 1) throw LackStackElementException();
    int element = stack.back();
    stack.pop_back();
    stack.insert(stack.begin() ,element);
}

void MyStack::rra(){
    internal_rr(stack_a);
}

void MyStack::rrb(){
    internal_rr(stack_b);
}