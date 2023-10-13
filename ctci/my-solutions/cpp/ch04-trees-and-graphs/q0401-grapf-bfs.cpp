/*
CTCI - Chapter 4 - Question 1

Given a directed graph, design an algorithm to find out whether there is a route
between two nodes

Solution: Both DFS and BFS work. For this problem BFS is more efficient.

Build:

Linux & Mac:
    g++ <file.cpp> or 
    g++ -std=c++11 <file.cpp> 

Windows (vcvarsall.bat):
    cl /EHsc <file.cpp>
*/

#include <iostream>
#include <cassert>

#include "lib/graph.h"

using namespace std;

void test_00()
{
    Graph<int> g;
    g.create_test_graph();

    int d1 = 1;
    int d2 = 5;
    bool result = g.are_nodes_connected(g.get_test_node(d1), g.get_test_node(d2));
    assert (result == false);
    cout << d1 << " is connected to " << d2 << ": " << result << endl;

    d1 = 2;
    d2 = 6;
    result = g.are_nodes_connected(g.get_test_node(d1), g.get_test_node(d2));
    assert (result == true);
    cout << d1 << " is connected to " << d2 << ": " << result << endl;
}

int main()
{
    test_00();

    return 0;
}
