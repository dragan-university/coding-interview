/*
CTCI - Chapter 4 - Question 4

Implement a function to check if a binary tree is balanced. For the purposes of
this question, a balanced tree is defined to be a tree such that the heights of the
two subtrees of any node never differ by more than one

---
There are two solutions implemented in the functions:
    BTree::isBalanced() and
    BTree::isBalanced2()

Here we test the functions

---
Build:
Windows (vcvarsall.bat):
cl /EHsc <file.cpp>
*/

#include <iostream>
#include <cassert>

#include "lib/btree.h"

using namespace std;

void test_00()
{
    cout << "empty tree is balanced" << endl;
    BTree<int> bt;

    assert (bt.is_balanced() == true);
}

void test_123_not_balanced()
{
    cout << "1-2-3 is not balanced" << endl;

    BTree<int> bt;

    bt.insert_in_order(1);
    bt.insert_in_order(2);
    bt.insert_in_order(3);

    assert (bt.is_balanced() == false);
}

void test_213_balanced()
{
    cout << "2-1-3 is balanced" << endl;

    BTree<int> bt;

    bt.insert_in_order(2);
    bt.insert_in_order(1);
    bt.insert_in_order(3);

    assert (bt.is_balanced() == true);
}

void test_2134_balanced()
{
    cout << "2-1-3-4 is balanced" << endl;

    BTree<int> bt;

    bt.insert_in_order(2);
    bt.insert_in_order(1);
    bt.insert_in_order(3);
    bt.insert_in_order(4);

    assert (bt.is_balanced() == true);
    assert (bt.is_balanced2() == true);
}

void test_21345_not_balanced()
{
    cout << "2-1-3-4-5 is not balanced" << endl;

    BTree<int> bt;

    bt.insert_in_order(2);
    bt.insert_in_order(1);
    bt.insert_in_order(3);
    bt.insert_in_order(4);
    bt.insert_in_order(5);

    assert (bt.is_balanced() == false);
    assert (bt.is_balanced2() == false);
}

void test_210345_not_balanced()
{
    cout << "2-1-0-3-4-5 is not balanced" << endl;

    BTree<int> bt;

    bt.insert_in_order(2);
    bt.insert_in_order(1);
    bt.insert_in_order(0);
    bt.insert_in_order(3);
    bt.insert_in_order(4);
    bt.insert_in_order(5);

    assert (bt.is_balanced() == false);
    assert (bt.is_balanced2() == false);
}

int main()
{
    test_00();
    test_123_not_balanced();
    test_213_balanced();
    test_2134_balanced();
    test_21345_not_balanced();
    test_210345_not_balanced();

    return 0;
}
