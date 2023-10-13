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
#include "BTree.h"

using namespace std;

void test_simple()
{
    BTree<int> bt;
    bt.insert_in_order(5);
    bt.insert_in_order(7);
    bt.insert_in_order2(3);
    bt.insert_in_order2(11);
    bt.insert_in_order2(1);
    bt.insert_in_order(4);
    cout << "print in order: 1, 3, 4, 5, 7, 11" << endl;
    bt.print_in_order();
    cout << "print bfs: 5, 3, 7, 1, 4, 11" << endl;
    bt.print_bfs();
}

int main()
{
    test_simple();

    return 0;
}
