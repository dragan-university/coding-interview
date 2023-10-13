/*
CTCI - Chapter 8 - Question 9

Parens: Implement an algorithm to print all valid (ie. properly opened and 
closed) combinations of n pairs of parenthesis.

Solution: 
We can build recursively, but it is not very efficient. We need to handle duplicates.

Better approach is to build the combinations followinf two rules:
- add left parens until we can (ie. we haven't used them all)
- add right if we used more left then right parens

This is also recursive function but it case n+1 doe snot build upon solution for case n

Example:
Build recursively ... it's possible but there are duplicates.

n=1
()

n=2
()() (()) ()()
(()) ()()

n=3
()(()) (()()) ((())) (()()) (())()
1      2      3      2      4
()()() (())() ()()() ()(()) ()()()
5      4      5      1      5

We don't implement this approach.

Build:

Linux & Mac:
    g++ <file.cpp> or 
    g++ -std=c++11 <file.cpp> 

Windows (vcvarsall.bat):
    cl /EHsc <file.cpp>
*/

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <ctime>

using namespace std;

void parens(
        vector<string> &parencombs,  // all parens combinations
        size_t n,      // number of paren pairs 
        size_t left,   // remaining left parens
        size_t right,  // remaining right parens 
        size_t index,  // index in current parencomb
        string &parencomb)  // current parens combination
{
    // if we haven't used all left parens add one
    if (left > 0) {
        parencomb[index] = '(';
        parens(parencombs, n, left-1, right, index+1, parencomb);
    }

    // if we used less right then left parens we can add right paren
    if (right > left) {
        parencomb[index] = ')';
        parens(parencombs, n, left, right-1, index+1, parencomb);
    }

    // if index is 2n we created a combination
    if (index == 2*n) {
        parencombs.push_back(parencomb);
        //cout << parencomb << endl;
    }
}

void parens(vector<string> &parencombs, int n) 
{
    string parencomb(2*n, '-');
    parens(parencombs, n, n, n, 0, parencomb);
}

void test_parens(int n, size_t expected_count)
{
    vector<string> parencombs;
    parens(parencombs, n);

    if (parencombs.size() == expected_count) {
        cout << "PASS" << endl;
    } else {
        cout << "FAIL: expected=" << expected_count << ", actual=" << parencombs.size() << endl;
    }

    cout << "result =====" << endl;
    for (size_t i=0; i<parencombs.size(); i++) {
        cout << parencombs[i] << endl;
    }
}

int main()
{
    test_parens(2, 2);
    test_parens(3, 5);
    test_parens(4, 14);

    return 0;
}
