#ifndef __LACKSTACKELEMENTEXCEPTION_H__
#define __LACKSTACKELEMENTEXCEPTION_H__

#include <iostream>
using namespace std;

class LackStackElementException : public std::exception {
    public:
        const char* what(){
            return "There is not enough elements in the stack.";
        }
};
#endif