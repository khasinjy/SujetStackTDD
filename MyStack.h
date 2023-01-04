#ifndef __MYSTACK_H__
#define __MYSTACK_H__

#include <vector>
#include <algorithm>
#include "EmptyStackException.h"
#include "LackStackElementException.h"

using namespace std;

class MyStack {
	private:
		vector<int> stack_a;
		vector<int> stack_b;
	public:
		MyStack();
        vector<int> getStackA();
        vector<int> getStackB();
        void setStackA(vector<int> stackA);
        void setStackB(vector<int> stackB);
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