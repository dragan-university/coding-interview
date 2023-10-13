/* 
even-tree.cpp

Discussion:

Solution: Assign weight of each node. If weight of root node is even then number
of cuts is equal to number of nodes with even weight minus 1. Otherwise no cut
is possible.

How to build:
Linux: g++ --std=c++11 <file>.cpp
Windows (vcvarsall.bat): cl /EHsc <file>.cpp
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
#include <cassert>
#include <string>

using namespace std;

const bool MY_DEBUG = false;

struct node
{
    int data;
    int weight;
    vector<node *> children;
};

void print_nodes(const string &message, const vector<node *> &nodes)
{
  if (MY_DEBUG) {
  cout << message << endl;
  for (unsigned i=0; i<nodes.size(); ++i) {
    cout << i <<
      " data:" << nodes[i]->data <<
      " w:" << nodes[i]->weight <<
      " #children:" << nodes[i]->children.size() << " ";

    for (unsigned j=0; j<nodes[i]->children.size(); ++j) {
      cout << nodes[i]->children[j]->data << ":";
    }
    cout << endl;
  }
  }
}

void print_edges(const vector<pair<int, int> > &edges)
{
  if (MY_DEBUG) {
  cout << "edges" << endl;
  for (unsigned i=0; i<edges.size(); ++i) {
    cout << i+1 <<
      " f:" << edges[i].first <<
      " s:" << edges[i].second <<
      endl;
  }
  }
}

void init_nodes(
    int N,  // in
    vector<pair<int, int> > &edges, // in
    vector<node *> &nodes // out
    )
{
  for (int i=0; i<N; ++i) {
    node *new_node = new node();
    new_node->data = i+1;
    new_node->weight = 0;

    nodes.push_back(new_node);
  }

  queue<int> nodes_to_process;
  vector<vector<pair<int, int> >::iterator> processed_edges; // processed edge
  nodes_to_process.push(1);

  print_edges(edges);

  while (!nodes_to_process.empty()) {
    int node_id = nodes_to_process.front();
    if (MY_DEBUG) cout << "process node " << node_id << endl;
    nodes_to_process.pop();

    for (unsigned i=0; i<edges.size(); ++i) {
      if (MY_DEBUG) cout << "edge: " << edges[i].first << ":" << edges[i].second << endl;

      if (edges[i].first == node_id) {
        nodes[node_id-1]->children.push_back(nodes[edges[i].second - 1]);
        nodes_to_process.push(edges[i].second);
        processed_edges.push_back(edges.begin()+i);
      }

      if (edges[i].second == node_id) {
        nodes[node_id-1]->children.push_back(nodes[edges[i].first - 1]);
        nodes_to_process.push(edges[i].first);
        processed_edges.push_back(edges.begin()+i);
      }
    }

    // remove processed edges from the list
    unsigned i = 0;
    for (auto it: processed_edges) {
      edges.erase(it-i);
      i++;
    }

    processed_edges.clear();
  }
}

int calculate_node_weight(node *n)
{
  n->weight = 1;
  if (MY_DEBUG) cout << "calculate_node_weight " << n->data << endl;
  if (n->children.size() > 0) {
    if (MY_DEBUG) cout << "node " << n->data << " has " << n->children.size() << " children" << endl;
    for (unsigned i=0; i<n->children.size(); ++i) {
      n->weight += calculate_node_weight(n->children[i]);
    }
  }

  return n->weight;
}

int even_tree(vector<node *> &nodes)
{
  // calculate node wieghts
  calculate_node_weight(nodes[0]);
  print_nodes("after weight calculation", nodes);

  int number_of_cuts = 0;

  if (nodes[0]->weight % 2 == 0) {
    int number_of_even_weights = 0;
    for (auto node: nodes) {
      if (node->weight % 2 == 0) {
        number_of_even_weights++;
      }
    }

    number_of_cuts = number_of_even_weights-1;
  }

  return number_of_cuts;
}

int even_tree(
    int N,
    vector<pair<int, int> > &edges)
{
  vector<node *> nodes;
  init_nodes(N, edges, nodes);

  print_nodes("after init nodes", nodes);

  return even_tree(nodes);
}

void test_my_01(void)
{
  int N = 5;
  int K = 4;

  vector<pair<int, int> > edges = {
    {2,1},
    {3,1},
    {4,3},
    {5,2},
    };

  int number_of_removed_edges = even_tree(N, edges);
  cout << number_of_removed_edges << endl;
  assert (number_of_removed_edges == 0);
}

void test_hr_sample(void)
{
  int N = 10;
  int K = 9;

  vector<pair<int, int> > edges = {
    {2,1},
    {3,1},
    {4,3},
    {5,2},
    {6,1},
    {7,2},
    {8,6},
    {9,8},
    {10,8}};

  int number_of_removed_edges = even_tree(N, edges);
  cout << number_of_removed_edges << endl;
  assert (number_of_removed_edges == 2);
}

void test_hr_01(void)
{
  int N = 20;
  int K = 19;

  vector<pair<int, int> > edges = {
    {2,1},
    {3,1},
    {4,3},
    {5,2},
    {6,5},
    {7,1},
    {8,1},
    {9,2},
    {10,7},
    {11,10},
    {12,3},
    {13,7},
    {14,8},
    {15,12},
    {16,6},
    {17,6},
    {18,10},
    {19,1},
    {20,8},
    };

  int number_of_removed_edges = even_tree(N, edges);
  cout << number_of_removed_edges << endl;
  assert (number_of_removed_edges == 4);
}

void test_hr_02(void)
{
  int N = 30;
  int K = 29;

  vector<pair<int, int> > edges = {
    {2,1},
    {3,2},
    {4,3},
    {5,2},
    {6,4},
    {7,4},
    {8,1},
    {9,5},
    {10,4},
    {11,4},
    {12,8},
    {13,2},
    {14,2},
    {15,8},
    {16,10},
    {17,1},
    {18,17},
    {19,18},
    {20,4},
    {21,15},
    {22,20},
    {23,2},
    {24,12},
    {25,21},
    {26,17},
    {27,5},
    {28,27},
    {29,4},
    {30,25},
    };

  int number_of_removed_edges = even_tree(N, edges);
  cout << number_of_removed_edges << endl;
  assert (number_of_removed_edges == 11);
}

void hr_testcase()
{
  int N;
  int M;
  cin >> N >> M;

  vector<pair<int, int> > edges(N);
  for (int i=0; i<M; ++i)
  {
    cin >> edges[i].first >> edges[i].second;
  }

  int number_of_removed_edges = even_tree(N, edges);
  cout << number_of_removed_edges << endl;
}

void hackerrank()
{
  hr_testcase();
}

int main()
{
  //hackerrank();
  test_my_01();
  test_hr_sample();
  test_hr_01();
  test_hr_02();
  return 0;
}