#ifndef __MYSTACK_H__
#define __MYSTACK_H__

#include <list>
#include <algorithm>
#include "EmptyStackException.h"
#include "LackStackElementException.h"

using namespace std;

class MyStack {
	private:
		list<int> stack_a;
		list<int> stack_b;
		int internal_front(list<int>& stack);
		int internal_back(list<int>& stack);
		void internal_s(list<int>& stack);
		void internal_p(list<int>& stackSource, list<int>& stackTarget);
		void internal_r(list<int>& stack);
		void internal_rr(list<int>& stack);
	public:
		MyStack();
        list<int> getStackA();
        list<int> getStackB();
        void setStackA(list<int> stackA);
        void setStackB(list<int> stackB);
		int front_a();
		int front_b();
		int back_a();
		int back_b();
		void sa();
		void sb();
		void pa();
		void pb();
		void ra();
		void rb();
		void rra();
		void rrb();
};

#endif