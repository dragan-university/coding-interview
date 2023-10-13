/*
---
Build:
Windows (vcvarsall.bat):
cl /EHsc <file.cpp>
*/

#include <iostream>
#include "stack.h"

using namespace std;

void test_pop_from_empty_stack()
{
    cout << "test pop from empty stack" << endl;
    ddn::stack<int> s;

    if (s.is_empty()) {
        cout << "OK: stack is empty" << endl;
    } else {
        cout << "FAIL: stack should be empty" << endl;
        return;
    }

    try {
        s.pop();
        cout << "FAIL: pop from empty stack must generate exception!";
        return;
    } catch(ddn::EmptyStackException& e) {
        cout << "OK: pop throws exception" << endl;
    }

    cout << "PASS" << endl << endl;
}

void test_push_peek_pop()
{
    cout << "test push - peek - pop" << endl;
    ddn::stack<int> s;

    s.push(5);
    cout << "stack is not empty -- ";
    if (s.is_empty()) {
        cout << "FAIL" << endl;
        return;
    } else {
        cout << "OK" << endl;
    }

    int v = s.peek();
    cout << "peek should return 5 -- ";
    if (v != 5) {
        cout << "FAIL" << endl;
        return;
    } else {
        cout << "OK" << endl;
    }

    cout << "stack is still not empty -- ";
    if (s.is_empty()) {
        cout << "FAIL" << endl;
        return;
    } else {
        cout << "OK" << endl;
    }

    v = s.pop();
    cout << "pop should return 5 -- ";
    if (v != 5) {
        cout << "FAIL" << endl;
        return;
    } else {
        cout << "OK" << endl;
    }

    cout << "stack is now empty -- ";
    if (s.is_empty()) {
        cout << "OK" << endl;
    } else {
        cout << "FAIL" << endl;
        return;
    }

    cout << "PASS" << endl << endl;
}

int main()
{
    test_pop_from_empty_stack();
    test_push_peek_pop();
    return 0;
}
