/*
Q 2.2 Return Kth to last
Implement an alghoritm to find the kth to last element of a singly linked list.
---
Examples:

list = 5 - 7 - 3 - 4 - 9 - 11
kth_to_last(list, 3) = 4

Questions to ask:

Solution: Use two pointers, where second pointer is k behind the first. When
first pointer reach the end, the second pointer is at the kth to last position.
---
Build:
Windows (vcvarsall.bat):
cl /EHsc <file.cpp>
*/
#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstring>

#include <string>
#include <unordered_set>

#include "lib/list.h"

using namespace std;

/*
complexity O(n) where n is the list size
*/
ddn::node<int>* kth_to_last(const ddn::list<int>& l, int k) {
    l.print();
    cout << "return " << k << "th to last" << endl;
    ddn::node<int>* a_node = l.get_head();

    int position = 0;
    while ((position < k) && a_node) {
        a_node = a_node->next;
        position++;
    }

    if (position < k) {
        return nullptr;
    }

    ddn::node<int>* k_node = l.get_head();
    while (a_node) {
        a_node = a_node->next;
        k_node = k_node->next;
    }

    return k_node;
}

void test_solution(const ddn::list<int>& l, int k, int expected) {
    int actual = kth_to_last(l, k)->data;

    if (actual == expected) {
        cout << "PASS: " << actual << endl;
    } else {
        cout << "FAIL: actual=" << actual << " expected=" << expected << endl;
    }
}

int main()
{
    ddn::list<int> l;
    l.push_front(5);
    l.push_back(7);
    l.push_back(3);
    l.push_back(4);
    l.push_back(9);
    l.push_back(11);

    test_solution(l, 3, 4);
    return 0;
}
