/*
CTCI - Chapter 4 - Question 2

Minimal Tree: Given a sorted (increasing order) array with unique integer 
elements, write an algorithm to create a binary search tree with minimal height.

Solution: Add middle element first. Then recursively add middle from left side
followed by the middle of right side. It stops when left and right are same or 
right is smaller then left.

Example: arr = {0,1,2,3,4}

must add in following sequence 2,1,0,4,3

Build:

Linux & Mac:
    g++ <file.cpp> or 
    g++ -std=c++11 <file.cpp> 

Windows (vcvarsall.bat):
    cl /EHsc <file.cpp>
*/

#include <iostream>
#include <cassert>

#include "lib/btree.h"

using namespace std;

void minimal_tree(
        BTree<int> &bt,
        int arr[],
        size_t first,
        size_t last) 
{
    bt.minimal_bst(arr, last - first + 1);
}

// arr is array of integers in increasing order
void test_minimal_tree(int arr[], size_t size, size_t expected_result)
{
    BTree<int> bt;
    bt.minimal_bst(arr, size);

    size_t actual_result = bt.get_height();

    std:cout << "expected=" << expected_result << ", actual=" << actual_result << endl;
    bt.print_in_order();
    assert(actual_result == expected_result);
}

void test_1()
{
    int arr[] = {1};
    test_minimal_tree(arr, sizeof(arr)/sizeof(int), 1);
}

void test_12()
{
    int arr[] = {1,2};
    test_minimal_tree(arr, sizeof(arr)/sizeof(int), 2);
}

void test_123()
{
    int arr[] = {1,2,3};
    test_minimal_tree(arr, sizeof(arr)/sizeof(int), 2);
}

void test_1_7()
{
    int arr[] = {1,2,3,4,5,6,7};
    test_minimal_tree(arr, sizeof(arr)/sizeof(int), 3);
}

void test_1_8()
{
    int arr[] = {1,2,3,4,5,6,7,8};
    test_minimal_tree(arr, sizeof(arr)/sizeof(int), 4);
}

int main()
{
    test_1();
    test_12();
    test_123();
    test_1_7();
    test_1_8();

    return 0;
}
