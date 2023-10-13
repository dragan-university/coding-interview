/*
---
Build:
Linux & Mac:
    g++ <file.cpp> or 
    g++ --std=c++11 <file.cpp> 
Windows (vcvarsall.bat):
    cl /EHsc <file.cpp>
*/

#include <iostream>
#include "heap.h"

using namespace std;

void test_simple()
{
    Heap<int> h;
    h.push(5);
    h.push(11);
    h.push(3);
    h.push(-2);
    h.push(15);

    cout << "popping" << endl;
    while (!h.empty()) {
        cout << h.pop() << ":";
    }
    cout << endl;
}

int main()
{
    test_simple();

    return 0;
}
