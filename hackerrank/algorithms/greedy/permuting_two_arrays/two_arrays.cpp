/*
https://www.hackerrank.com/challenges/two-arrays

Discussion:
- sort one list in acsending order and the other in descending order.
- then add elements with same index
- if all sums are ok then we have solution, otherwise not

How to build:
Linux: g++ --std=c++11 <file>.cpp
Windows (vcvarsall.bat): cl /EHsc <file>.cpp
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool two_arrays_solution(vector<int> &a, vector<int> &b, int k)
{
    size_t n = a.size();

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (size_t i=0; i<n; ++i) {
        if (a[i]+b[n-i-1] < k) {
            return false;
        }
    }

    return true;
}

void test_two_arrays_solution(vector<int> &a, vector<int> &b, int k, bool expected)
{
    cout << "=== begin test case ===" << endl;
    bool actual = two_arrays_solution(a, b, k);

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
    vector<int> a = {2,1,3};
    vector<int> b = {7,8,9};
    bool expected = true;

    test_two_arrays_solution(a, b, 10, expected);
}

void test_hr_sample2() 
{
    vector<int> a = {1,2,2,1};
    vector<int> b = {3,3,3,4};
    bool expected = false;

    test_two_arrays_solution(a, b, 5, expected);
}

void hr_query()
{
    int n;
    int k;
    cin >> n >> k;

    vector<int> a(n);
    for (size_t i=0; i<n; i++) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (size_t i=0; i<n; i++) {
        cin >> b[i];
    }

    bool result = two_arrays_solution(a, b, k);

    if (result) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << endl;
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
