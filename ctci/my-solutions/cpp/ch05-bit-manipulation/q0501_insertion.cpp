/*
CTCI - Chapter 5 - Question 1

Insertion: You are given two 32-bit numbers, N and M, and two bit positions, i
and j. Write a method to insert M into N such that M starts at bit j and ends at
bit i. You can assume that the bits j through i have enough space to fit all of
M. That is, if M=10011, you can assume that there are at least 5 bits between
j and i. You would not, for example, have j=3 and i=2, because M cannot fully
fit between bit 3 and bit 2.

Examples:

Input: N=10000000000, M=10011, i=2, j=6
Output: N=10001001100

Solution:

Build:

Linux & Mac:
    g++ <file.cpp> or
    g++ -std=c++11 <file.cpp>

Windows (vcvarsall.bat):
    cl /EHsc <file.cpp>
*/

#include <iostream>
#include <cassert>
#include <ctime>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

unsigned solution(unsigned N, unsigned M, unsigned i, unsigned j)
{
    cout << "MO=" << bitset<32>(M) << endl;
    M = M<<i;
    cout << "MS=" << bitset<32>(M) << endl;

    unsigned j1 = (1<<j+1) - 1;
    cout << "2^" << j << "=" << bitset<32>(j1) << endl;
    unsigned i1 = (1<<i) - 1;
    cout << "2^" << i << "=" << bitset<32>(i1) << endl;

    unsigned mask = j1 - i1;
    cout << "mask1: " << bitset<32>(mask) << endl;
    mask = 0xFFFFFFFF - mask;
    cout << "mask2: " << bitset<32>(mask) << endl;

    N = N & mask;
    N = N | M;
    return N;
}

void test_solution(
        unsigned N,
        unsigned M,
        unsigned i,
        unsigned j,
        unsigned expected_result)
{
    int actual_result = solution(N, M, i, j);
    cout << "E:" << bitset<32>(expected_result);
    cout << " A:" << bitset<32>(actual_result) << endl;
    //assert(actual_result == expected_result);
}

void test_01_01()
{
    test_solution(0x400, 0x13, 2, 6, 0x44C);
}

int main()
{
    test_01_01();

    return 0;
}
