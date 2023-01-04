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
    stack_a.erase(stack_a.begin());
    stack_b.insert(stack_b.begin(), firstA);
}

void MyStack::pb(){
    if(stack_b.empty()) throw EmptyStackException();
    int firstB = stack_b.front();
    stack_b.erase(stack_b.begin());
    stack_a.insert(stack_a.begin(), firstB);
}

void MyStack::ra(){
    if(stack_a.empty()) throw EmptyStackException();
    if(stack_a.size() == 1) throw LackStackElementException();
    int element = stack_a.front();
    stack_a.erase(stack_a.begin());
    stack_a.push_back(element);
}

void MyStack::rb(){
    if(stack_b.empty()) throw EmptyStackException();
    if(stack_b.size() == 1) throw LackStackElementException();
    int element = stack_b.front();
    stack_b.erase(stack_b.begin());
    stack_b.push_back(element);
}

void MyStack::rra(){
    if(stack_a.empty()) throw EmptyStackException();
    if(stack_a.size() == 1) throw LackStackElementException();
    int element = stack_a.back();
    stack_a.pop_back();
    stack_a.insert(stack_a.begin(), element);
}

void MyStack::rrb(){
    if(stack_b.empty()) throw EmptyStackException();
    if(stack_b.size() == 1) throw LackStackElementException();
    int element = stack_b.back();
    stack_b.pop_back();
    stack_b.insert(stack_b.begin(), element);
}