/*
CTCI - Chapter 4 - Question 3

List of Depth: Given a binary tree, design an algorithm which creates a linked 
list of all the nodes at each depth (e.g. if you have a tree with depth D you'll 
have D linked lists).

Solution: 
- Use BFS
- keep track about depth
  - use 2 queues ... for working level and next level
  - once we process all nodes from a working level we initialize new level
    which becomes new next, while current next becomes working

Example: 
  1
      2
          5
              9
          6
      3
          7
          8

1
2 3
5 6 7 8
9

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

void list_of_depths(BTree<int> &bt, vector<queue<BTreeNode<int> *> > &lod)
{
    // working level = root
    // next level = empty
    queue<BTreeNode<int> *> *working_level = new queue<BTreeNode<int> *>();
    working_level->push(bt.root);
    queue<BTreeNode<int> *> *next_level = new queue<BTreeNode<int> *>();
    lod.push_back(*working_level);

    // while working level is not empty
    while (!working_level->empty()) {
        // pop node from working
        BTreeNode<int> *node = working_level->front();
        working_level->pop();
        
        // add node's children to next level
        if (node->left) next_level->push(node->left);
        if (node->right) next_level->push(node->right);

        // if working level is empty
        if (working_level->empty() && !next_level->empty()) {
            working_level = next_level;
            lod.push_back(*working_level);
            next_level = new queue<BTreeNode<int> *>();              
        }
    }
}

void test_list_of_depths(BTree<int> &bt, size_t expected_lod_size)
{
    vector<queue<BTreeNode<int> *> > actual_lod;
    list_of_depths(bt, actual_lod);

    cout << "LOD: ";
    bt.print_in_order(true);
    cout << endl;
    for (size_t level=0; level < actual_lod.size(); ++level){
        cout << "Level: " << level << endl;
        while (!actual_lod[level].empty()) {
            BTreeNode<int> *node = actual_lod[level].front();
            actual_lod[level].pop();
            cout << node->get_data() << ":";
        }
        cout << endl;
    }
    assert(actual_lod.size() == expected_lod_size);
}

void test_1()
{
    BTree<int> bt;
    int arr[] = {1};
    bt.minimal_bst(arr, sizeof(arr)/sizeof(int));

    test_list_of_depths(bt, 1);
}

void test_12()
{
    BTree<int> bt;
    int arr[] = {1,2};
    bt.minimal_bst(arr, sizeof(arr)/sizeof(int));

    test_list_of_depths(bt, 2);
}

void test_123()
{
    BTree<int> bt;
    int arr[] = {1,2,3};
    bt.minimal_bst(arr, sizeof(arr)/sizeof(int));

    test_list_of_depths(bt, 2);
}

void test_1_7()
{
    BTree<int> bt;
    int arr[] = {1,2,3,4,5,6,7};
    bt.minimal_bst(arr, sizeof(arr)/sizeof(int));

    test_list_of_depths(bt, 3);
}

void test_1_8()
{
    BTree<int> bt;
    int arr[] = {1,2,3,4,5,6,7,8};
    bt.minimal_bst(arr, sizeof(arr)/sizeof(int));

    test_list_of_depths(bt, 4);
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
