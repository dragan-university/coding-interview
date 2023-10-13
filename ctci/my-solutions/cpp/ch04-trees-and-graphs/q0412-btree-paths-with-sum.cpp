/*
CTCI - Chapter 4 - Question 12

Paths with Sum: Yuo are given a binary tree in which each node contains an
integer value (which might be positive or negative). Design an algorithm to find
the number of paths that sum to a given value. The path does not need to start
or end at the root or a leaf, but it must go downwards (travelling only from
parent node to child nodes).

---
Example:

Tree:
10
    5
        3
            3
            -2
        2
            1
    -3
        11

Sum: 8

Paths:
1. -3, 11
2. 5, 2, 1
3. 5, 3
---
Solution:

node = 10
sum = 10
path = 10
  node->left
  node = 5
  sum = 15
  path = 10,5
    node->left
    node = 3
    sum = 18
    path = 10,5,3
      node->left
      node = 3
      sum = 21
      path = 10,5,3,3
        node->left
        node = null
        node->right
        node = nullptr
      sum = 18
      path = 10,5,3
      node->right
      node = -2
      sum = 16
      path = 10,5,3,-2
      sum = 18
      path = 10,5,3
    sum = 15
    path = 10,5
    node->right
    node = 2
    sum = 17
    path = 10,5,2
    ...


---
Build:
Windows (vcvarsall.bat):
cl /EHsc <file.cpp>
*/

#include <iostream>
#include <cassert>
#include <vector>

#include "lib/btree.h"

using namespace std;

// Input: node
// Input: sum
// Output: running_paths (this is just intermediate storage for recursive calls)
// Output: paths (this is real result)
void paths_with_sum(
        BTreeNode<int> *node,
        int sum,
        vector<pair<int, vector<int> > > &running_paths,
        vector<vector<int> > &paths) {

    if (node == nullptr) {
        return;
    }

    cout << "node: " << node->data << endl;

    // add new running_path for this node
    vector<int> running_path;
    pair<int, vector<int> > new_running_path = make_pair(0, running_path);
    running_paths.push_back(new_running_path);

    // add value of this node to the running paths and check if some equal to sum
    auto rpit = running_paths.begin();
    while (rpit != running_paths.end()) {
        rpit->first += node->data;
        rpit->second.push_back(node->data);

        if (rpit->first == sum) {
            paths.push_back(rpit->second);
        }

        ++rpit;
    }

    // recursive calls
    paths_with_sum(node->left, sum, running_paths, paths);
    paths_with_sum(node->right, sum, running_paths, paths);

    // remove this node's value from all running paths
    // also make sure sum for each running path is decreased for the value
    for (auto rpit = running_paths.begin(); rpit != running_paths.end(); ++rpit) {
        cout << "pop_el:";
        int last_data = rpit->second.back();
        rpit->second.pop_back();
        if (rpit->second.empty()) {
            cout << "pop_path";
        } else {
            rpit->first -= last_data;
        }
    }

    // last running path (which was containing only this node) is now empty so
    // we must remove it
    running_paths.pop_back();
    cout << endl;
}

void test_0() {
    BTreeNode<int> *r = new BTreeNode<int>(10);
    BTreeNode<int> *rl = new BTreeNode<int>(5, r);
    BTreeNode<int> *rll = new BTreeNode<int>(3, rl);
    BTreeNode<int> *rlll = new BTreeNode<int>(3, rll);
    BTreeNode<int> *rllr = new BTreeNode<int>(-2, rll);
    rll->left = rlll;
    rll->right = rllr;
    BTreeNode<int> *rlr = new BTreeNode<int>(2, rl);
    BTreeNode<int> *rlrl = new BTreeNode<int>(1, rlr);
    rlr->left = rlrl;
    rl->left = rll;
    rl->right = rlr;
    BTreeNode<int> *rr = new BTreeNode<int>(-3, r);
    BTreeNode<int> *rrl = new BTreeNode<int>(11, rr);
    rr->left = rrl;
    r->left = rl;
    r->right = rr;

    BTree<int> bt(r);
    bt.print_bfs();

    vector<vector<int> > paths;
    vector<pair<int, vector<int> > > running_paths;
    int sum = 8;
    paths_with_sum(r, sum, running_paths, paths);

    cout << "Number of paths: " << paths.size() << endl;
    for (size_t p=0; p<paths.size(); ++p) {
        cout << "path " << p << ": ";
        for (auto it = paths[p].begin(); it != paths[p].end(); ++it) {
            cout << *it << ",";
        }
        cout << endl;
    }
}

int main()
{
    test_0();

    return 0;
}
