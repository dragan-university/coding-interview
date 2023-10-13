/*
Q 2.4 Partition list
Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater or
equal to x.
---
Examples:

list = 5 - 7 - 3 - 4 - 9 - 11
x = 6
5 - 3 - 4 - 7 - 9 - 11

Questions to ask:
- can we add to the beginning and the of the list? if yes, we can do in place, otherwise we need additional list

Solution:
- with head and tail pointers:
  if element is smaller than x it goes to the beginning of the list otherwise to the end of the list
---
Build:
Linux/Mac: g++ --std=c++11 <file.cpp>
Windows (vcvarsall.bat): cl /EHsc <file.cpp>
*/
#include <iostream>
#include <vector>
#include <string>
#include "lib/list.h"
using namespace std;

const bool DEBUG = true;

/*
complexity ...
*/
void partition_list(ddn::list<int>& l, int x) {
    if (DEBUG) l.print();

    ddn::node<int>* current = l.get_head();
    for (size_t i=0; i<l.size(); ++i) {
        if (current->data < x) {
            l.push_front(current->data);
            l.remove(current);
        } else {
            l.push_back(current->data);
            l.remove(current);
        }

        current = current->next;
    }
}

void test_solution(ddn::list<int>& l, int x, vector<int>& expected) {
    partition_list(l, x);

    if (l.size() != expected.size()) {
        cout << "FAIL: incorrect size!" << endl;
        return;
    }

    ddn::node<int>* current = l.get_head();
    for (size_t i; i< expected.size(); ++i) {
        if (current->data != expected[i]) {
            cout << "FAIL: index " << i << endl;
        }

        current = current->next;
    }

    cout << "PASS!" << endl;
}

void tc_01()
{
    ddn::list<int> l;
    l.push_front(5);
    l.push_back(7);
    l.push_back(3);
    l.push_back(4);
    l.push_back(9);
    l.push_back(11);

    vector<int> expected({4,3,5,7,9,11});

    test_solution(l, 6, expected);
}

int main()
{
    tc_01();
    return 0;
}
