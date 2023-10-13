// insertion-sort-part1.cpp
//
// How to build:
// Linux: g++ -std-c++1 <file>.cpp
// Windows: cl /EHsc <file>.cpp
// Windows environment setup: run vcvarsall.bat

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

void print_vector(const vector<int>& v) {
    for (auto item: v) {
        cout << item << " ";
    }

    cout << endl;
}

void insertionSort(vector<int> ar) {
    int e = *(ar.end()-1);

    for (auto it=ar.end()-2; it>=ar.begin(); it--) {
        if (e < *it) {
            *(it+1) = *it;
            print_vector(ar);
        } else {
            *(it+1) = e;
            print_vector(ar);
            return;
        }
    }

    ar[0] = e;
    print_vector(ar);
}

void test_010_hr()
{
    vector<int> v {2,4,6,8,3};
    print_vector(v);

    insertionSort(v);
}

void test_020_my()
{
    vector<int> v {2,4,6,8,1};
    print_vector(v);

    insertionSort(v);
}

void hackerrank()
{
    vector<int> _ar;
    int _ar_size;
    cin >> _ar_size;

    for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp);
    }

    insertionSort(_ar);
}

#define RUNTESTS (1)

int main(void) {
    #ifdef RUNTESTS
    //test_010_hr();
    test_020_my();
    #else
    hackerrank();
    #endif

    return 0;
}
