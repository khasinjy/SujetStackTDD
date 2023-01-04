#ifndef __LACKSTACKELEMENTEXCEPTION_H__
#define __LACKSTACKELEMENTEXCEPTION_H__

class LackStackElementException : public std::exception {
    public:
        const char* what(){
            return "There is not enough elements in the stack.";
        }
};
#endif