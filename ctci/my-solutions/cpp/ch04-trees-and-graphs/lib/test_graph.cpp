/*
---
Build:

Linux & Mac:
    g++ <file.cpp> or 
    g++ -std=c++11 <file.cpp> 

Windows (vcvarsall.bat):
    cl /EHsc <file.cpp>
*/

#include <iostream>
#include "graph.h"

using namespace std;

void test_simple()
{
    Graph<int> g;
    g.create_directed_test_graph();
    
    cout << "print dfs: 1, 2, 3, 6, 7, 5, 4" << endl;
    g.print_dfs();
    cout << "print bfs: 1, 2, 3, 4, 6, 7, 5" << endl;
    g.print_bfs();
}

int main()
{
    test_simple();

    return 0;
}
