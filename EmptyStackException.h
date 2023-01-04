#ifndef __EMPTYSTACKEXCEPTION_H__
#define __EMPTYSTACKEXCEPTION_H__

#include <iostream>
using namespace std;

class EmptyStackException : public std::exception {
    public:
        const char* what(){
            return "Stack is empty.";
        }
};
#endif