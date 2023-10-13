/*
Build:

Linux & Mac:
    g++ <file.cpp> or 
    g++ --std=c++11 <file.cpp> 

Windows (vcvarsall.bat):
    cl /EHsc <file.cpp>
*/
#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

template<typename T> struct ListNode {
    T data;
    ListNode *next;

    ListNode(const T& _data, ListNode* _next=nullptr): data(_data), next(_next) {};
};

ListNode<string>* kth_to_last_node(size_t position, ListNode<string>* root) {
    ListNode<string>* node = root;
    for (size_t i=0; i<position; ++i) {
        node = node->next;
    }

    ListNode<string>* kth = root;
    while (node) {
        kth = kth->next;
        node = node->next;
    }
    
    return kth;
}

int main() {
    ListNode<string> a("Angel Food");
    ListNode<string> b("Bundt");
    ListNode<string> c("Cheese");
    ListNode<string> d("Devil's Food");
    ListNode<string> e("Eccles");

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;

    ListNode<string>* node = kth_to_last_node(2, &a);

    if (node == &d) {
        cout << "PASS: " << node->data;
    } else {
        cout << "FAIL: expected: " << d.data << ", actual: "<< node->data;
    }
    
    cout << endl;
    return 0;
}
