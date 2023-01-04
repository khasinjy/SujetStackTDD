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