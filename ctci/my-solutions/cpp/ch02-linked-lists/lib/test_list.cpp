/*
---
Build:
Windows (vcvarsall.bat):
cl /EHsc <file.cpp>
*/

#include <iostream>
#include "list.h"

using namespace std;

void test_adding_a_few_items()
{
    cout << "adding_a_few_items test -- print 7, 5, 3" << endl;
    ddn::list<int> l;
    l.push_front(5);
    l.push_front(7);
    l.push_back(3);
    l.print();
}

void test_delete()
{
    cout << "delete test -- first print 7, 5, 3 -- then 7, 3" << endl;
    ddn::list<int> l;
    l.push_front(5);
    l.push_front(7);
    l.push_back(3);
    l.print();
    l.remove(5);
    l.print();
}

void test_is_same()
{
    cout << "is_same test" << endl;

    ddn::list<int> l;
    l.push_front(5);
    l.push_front(7);
    l.push_back(3);

    ddn::list<int> l2;
    l2.push_front(5);
    l2.push_front(7);
    l2.push_back(3);

    l.print();
    l2.print();
    if (l.is_same(l2)) {
        cout << "correct: l and l2 are same" << endl;
    } else {
        cout << "incorrect: l and l2 are same" << endl;
    }

    l.remove(5);
    l.print();
    l2.print();
    if (l.is_same(l2)) {
        cout << "incorrect: l and l2 are NOT same" << endl;
    } else {
        cout << "correct: l and l2 are not same" << endl;
    }
}

int main()
{
    //test_adding_a_few_items();
    //test_delete();
    test_is_same();

    return 0;
}
