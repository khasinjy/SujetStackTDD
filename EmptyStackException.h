#ifndef __EMPTYSTACKEXCEPTION_H__
#define __EMPTYSTACKEXCEPTION_H__

class EmptyStackException : public std::exception {
    public:
        const char* what(){
            return "Stack is empty.";
        }
};
#endif