#include "MyStack.h"

MyStack::MyStack(){
    stack_a = {};
    stack_b = {};
}

list<int> MyStack::getStackA(){
    return stack_a;
}

list<int> MyStack::getStackB(){
    return stack_b;
}

void MyStack::setStackA(list<int> stackA){
    stack_a = stackA;
}

void MyStack::setStackB(list<int> stackB){
    stack_b = stackB;
}

int MyStack::internal_front(list<int>& stack){
    if(stack.empty()) throw EmptyStackException();
    return stack.front();
}

int MyStack::front_a(){
    return internal_front(stack_a);
}

int MyStack::front_b(){
    return internal_front(stack_b);
}

int MyStack::internal_back(list<int>& stack){
    if(stack.empty()) throw EmptyStackException();
    return stack.back();
}

int MyStack::back_a(){
    return internal_back(stack_a);
}

int MyStack::back_b(){
    return internal_back(stack_b);
}

void MyStack::internal_s(list<int>& stack){
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

void MyStack::internal_p(list<int>& stackSource, list<int>& stackTarget){
    if(stackSource.empty()) throw EmptyStackException();
    int first = stackSource.front();
    stackSource.pop_front();
    stackTarget.push_front(first);
}

void MyStack::pa(){
    internal_p(stack_a, stack_b);
}

void MyStack::pb(){
    internal_p(stack_b, stack_a);
}

void MyStack::internal_r(list<int>& stack){
    if(stack.empty()) throw EmptyStackException();
    if(stack.size() == 1) throw LackStackElementException();
    int element = stack.front();
    stack.pop_front();
    stack.push_back(element);
}

void MyStack::ra(){
    internal_r(stack_a);
}

void MyStack::rb(){
    internal_r(stack_b);
}

void MyStack::internal_rr(list<int>& stack){
    if(stack.empty()) throw EmptyStackException();
    if(stack.size() == 1) throw LackStackElementException();
    int element = stack.back();
    stack.pop_back();
    stack.push_front(element);
}

void MyStack::rra(){
    internal_rr(stack_a);
}

void MyStack::rrb(){
    internal_rr(stack_b);
}