/*
CTCI - Chapter 4 - Question 6

Successor: Write an algorithm to find the 'next' (i.e. in-order successor) of a
given node in a BST. You may assume that each node has a link to its parent.

---
Solutions is implemented in the function:
    BTree::find_successor()
Refer to the function to understand the algorithm.

Here we test the functions

---
Build:
Linux & Mac:
    g++ <file.cpp> or
    g++ --std=c++11 <file.cpp>
Windows (vcvarsall.bat):
    cl /EHsc <file.cpp>
*/

#include <iostream>
#include <cassert>

#include "lib/btree.h"

using namespace std;

void test_00()
{
    BTreeNode<int> *n5 = new BTreeNode<int>(5);
    BTreeNode<int> *n6 = new BTreeNode<int>(6,nullptr,n5,nullptr);
    BTreeNode<int> *n4 = new BTreeNode<int>(4);
    BTreeNode<int> *n3 = new BTreeNode<int>(3,nullptr,n4,n6);
    BTreeNode<int> *n2 = new BTreeNode<int>(2);
    BTreeNode<int> *n1 = new BTreeNode<int>(1,nullptr,n3,n2);

    BTree<int> bt(n1);

    assert (bt.first_common_ancestor(n4, n5) == n3);
    assert (bt.first_common_ancestor(n2, n5) == n1);
}

int main()
{
    test_00();
    return 0;
}
