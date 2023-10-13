/*
Q 2.1 Write code to remove duplicates from an unsorted linked list.

FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed?
Hints: #9, #40
---
Examples:

list = 5 - 7 - 5 - 3 - 7 - 5
remove(list) = 5 - 7 - 3

Questions to ask:

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

we need to check every element in the list and that is O(n)

all operations inside the while loop are O(1) (including unordered_set.find)
*/
void remove_dups(ddn::list<int>& l) {
    unordered_set<int> unique_items;
    ddn::node<int>* a_node = l.get_head();
    unique_items.insert(a_node->data);

    while (a_node->next) {
        auto found = unique_items.find(a_node->next->data);
        if (found != unique_items.end()) {
            auto to_delete = a_node->next;
            a_node->next = a_node->next->next;
            delete to_delete;
        } else {
            unique_items.insert(a_node->next->data);
            a_node = a_node->next;
        }
    }
}

/*
This version does not remove last element in the list. Why?
*/
void remove_dups_2(ddn::list<int>& l) {
    unordered_set<int> unique_items;
    ddn::node<int>* a_node = l.get_head();

    while(a_node) {
        cout << "checking item: " << a_node->data << endl;
        auto found = unique_items.find(a_node->data);
        if (found != unique_items.end()) {
            cout << "found " << a_node->data << endl;
            if (a_node->next) {
                a_node->data = a_node->next->data;
                auto to_delete = a_node->next;
                a_node->next = a_node->next->next;
                delete to_delete;
            } else {
                cout << "delete last node" << endl;
                delete a_node;
                a_node = NULL;
            }
        } else {
            unique_items.insert(a_node->data);
            a_node = a_node->next;
        }
    }
}

void test_remove_dups(ddn::list<int>& l, ddn::list<int>& expected) {
    l.print("original list");
    remove_dups(l);

    l.print("list after removing dups");
    if (l.is_same(expected)) {
        cout << "PASS" << endl;
    } else {
        expected.print("expected");
        cout << "FAIL" << endl;
    }
}

int main()
{
    ddn::list<int> l;
    l.push_front(5);
    l.push_back(7);
    l.push_back(5);
    l.push_back(3);
    l.push_back(7);
    l.push_back(5);

    ddn::list<int> expected;
    expected.push_front(5);
    expected.push_back(7);
    expected.push_back(3);

    test_remove_dups(l, expected);
    return 0;
}
