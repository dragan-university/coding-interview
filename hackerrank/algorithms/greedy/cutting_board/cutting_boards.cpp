/*
https://www.hackerrank.com/challenges/board-cutting

Discussion:
- sort cut costs per dimension
- then always cut along the line of highest cost
- open: how can we prove that this lead to the solution

How to build:
Linux: g++ --std=c++11 <file>.cpp
Windows (vcvarsall.bat): cl /EHsc <file>.cpp
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;

const bool DEBUG = false;

void print_vector(const vector<long> &v)
{
    for (auto e: v)
    {
        cout << e << ":";
    }
    cout << endl;
}

long cut_board_solution(vector<long> &cx, vector<long> &cy)
{
    if (DEBUG) {
        print_vector(cx);
        print_vector(cy);
    }

    sort(cx.begin(), cx.end(), greater<long>());
    sort(cy.begin(), cy.end(), greater<long>());

    size_t ix = 0;
    size_t iy = 0;
    size_t nx = 0;
    size_t ny = 0;
    long cost = 0;
    while (ix < cx.size() || iy < cy.size()) {
        if (DEBUG) cout << "cx=" << cx[ix] << " cy=" << cy[iy] << endl;

        if (ix == cx.size()) {
            cost += (cy[iy] * (nx+1));
            iy++;
        } else if (iy == cy.size()) {
            cost += (cx[ix] * (ny+1));
            ix++;
        } else if (cx[ix] > cy[iy]) {
            cost += (cx[ix] * (ny+1));
            nx++;
            ix++;
        } else {
            cost += (cy[iy] * (nx+1));
            ny++;
            iy++;
        }

        if (DEBUG) cout << "cost=" << cost << endl;
    }

    const long MOD = 1000000007L;
    if (DEBUG) cout << "cost final=" << cost << " MOD=" << MOD << endl;
    return cost % MOD;
}

void test_cut_board_solution(vector<long> &cx, vector<long> &cy, long expected)
{
    cout << "=== begin test case ===" << endl;
    long actual = cut_board_solution(cx, cy);
    if (DEBUG) cout << "actual=" << actual << endl;

    if (actual == expected) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;
}

void test_01()
{
}

void test_hr_sample1()
{
    vector<long> cy = {2};
    vector<long> cx = {1};
    long expected = 4;

    test_cut_board_solution(cx, cy, expected);
}

void test_hr_sample2()
{
    vector<long> cy = {2,1,3,1,4};
    vector<long> cx = {4,1,2};
    long expected = 42;

    test_cut_board_solution(cx, cy, expected);
}

void hr_query()
{
    long n;
    long m;
    cin >> m >> n;

    vector<long> cy(m-1);
    for (size_t i=0; i<m-1; i++) {
        cin >> cy[i];
    }

    vector<long> cx(n-1);
    for (size_t i=0; i<n-1; i++) {
        cin >> cx[i];
    }

    long result = cut_board_solution(cx, cy);
    cout << result << endl;
}

void hackerrank()
{
    int q;
    cin >> q;

    for (size_t i=0; i<q; i++) {
        hr_query();
    }
}

int main() {
    //hackerrank();
    test_hr_sample1();
    test_hr_sample2();
    //test_01();
    return 0;
}
