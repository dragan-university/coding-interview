/*
---
Build:
Windows (vcvarsall.bat):
cl /EHsc <file.cpp>
---
Tags: c++ inheritance template relative_include
*/


#ifndef __DDN_STACK_H__
#define __DDN_STACK_H__

#include <exception>
#include "../../ch02-linked-lists/lib/list.h"

namespace ddn {
struct EmptyStackException : public std::exception
{
  const char * what () const throw ()
  {
    return "Empty Stack Exception";
  }
};

template <typename T>
class stack : public list<T>
{
public:
    T pop() {
        T data = peek();
        node<T>* to_delete = head;
        head = head->next;
        delete to_delete;
        return data;
    }

    void push(const T& data) {
        push_front(data);
    }

    T peek() {
        if (head == NULL) {
            throw EmptyStackException();
        }

        return head->data;
    }

    bool is_empty() {
        return (head == NULL);
    }
};
}

#endif  // __DDN_STACK_H__