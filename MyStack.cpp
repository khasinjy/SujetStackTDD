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

int MyStack::front_a(){
    if(stack_a.empty()) throw EmptyStackException();
    return stack_a.front();
}

int MyStack::front_b(){
    if(stack_b.empty()) throw EmptyStackException();
    return stack_b.front();
}

int MyStack::back_a(){
    if(stack_a.empty()) throw EmptyStackException();
    return stack_a.back();
}

int MyStack::back_b(){
    if(stack_b.empty()) throw EmptyStackException();
    return stack_b.back();
}

void MyStack::sa(){
    if(stack_a.empty()) throw EmptyStackException();
    if(stack_a.size() == 1) return;
    auto firstIt = stack_a.begin();
    auto secondIt = next(firstIt, 1);
    iter_swap(firstIt, secondIt);
}

void MyStack::sb(){
    if(stack_b.empty()) throw EmptyStackException();
    if(stack_b.size() == 1) return;
    auto firstIt = stack_b.begin();
    auto secondIt = next(firstIt, 1);
    iter_swap(firstIt, secondIt);
}

void MyStack::pa(){
    if(stack_a.empty()) throw EmptyStackException();
    int firstA = stack_a.front();
    stack_a.pop_front();
    stack_b.push_front(firstA);
}

void MyStack::pb(){
    if(stack_b.empty()) throw EmptyStackException();
    int firstB = stack_b.front();
    stack_b.pop_front();
    stack_a.push_front(firstB);
}

void MyStack::ra(){
    if(stack_a.empty()) throw EmptyStackException();
    if(stack_a.size() == 1) throw LackStackElementException();
    int element = stack_a.front();
    stack_a.pop_front();
    stack_a.push_back(element);
}

void MyStack::rb(){
    if(stack_b.empty()) throw EmptyStackException();
    if(stack_b.size() == 1) throw LackStackElementException();
    int element = stack_b.front();
    stack_b.pop_front();
    stack_b.push_back(element);
}

void MyStack::rra(){
    if(stack_a.empty()) throw EmptyStackException();
    if(stack_a.size() == 1) throw LackStackElementException();
    int element = stack_a.back();
    stack_a.pop_back();
    stack_a.push_front(element);
}

void MyStack::rrb(){
    if(stack_b.empty()) throw EmptyStackException();
    if(stack_b.size() == 1) throw LackStackElementException();
    int element = stack_b.back();
    stack_b.pop_back();
    stack_b.push_front(element);
}