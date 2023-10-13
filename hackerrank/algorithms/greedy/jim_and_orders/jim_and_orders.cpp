/*
https://www.hackerrank.com/challenges/jim-and-the-orders

Discussion:
- create list of pairs where first element is order number and second element
  is time to complete.
- then sort the list by the second element then first element
- time complexity: O(n*log(n)) same as sorting

Solution:
- use multiset, where we need to define comp function to compare first second
  elements, then first

How to build:
Linux: g++ --std=c++11 <file>.cpp
Windows (vcvarsall.bat): cl /EHsc <file>.cpp
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct ccomp
{
    bool operator() (const pair<int, int> & lhs, const pair<int, int> &rhs) const {
        if (lhs.second == rhs.second) {
            return (lhs.first < rhs.first);
        }

        return (lhs.second < rhs.second);
    }
};

void jim_solution(vector<int> &t, vector<int> &d, vector<int> &result)
{
    size_t n = t.size();
    set<pair<int, int>, ccomp> orders_by_completion;

    for (size_t i=0; i<n; ++i) {
        orders_by_completion.insert(make_pair(i+1, t[i]+d[i]));
    }

    for (auto it=orders_by_completion.begin(); it!=orders_by_completion.end(); ++it) {
        result.push_back(it->first);
    }
}

bool check_result(vector<int> &actual, vector<int> &expected)
{
    if (actual.size() != expected.size()) {
        cout << "invalid size" << endl;
        return false;
    }

    for (size_t i=0; i<actual.size(); ++i) {
        if (actual[i] != expected[i]) {
            cout << "order " << i << " not as expected" << endl;
            return false;
        }
    }

    return true;
}

void test_jim_solution(vector<int> &t, vector<int> &d, vector<int> &expected)
{
    cout << "=== begin test case ===" << endl;
    vector<int> actual;
    jim_solution(t, d, actual);

    if (check_result(actual, expected) == true) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;
}

void test_01() 
{
}

void test_hr_sample0() 
{
    vector<int> t = {1, 2, 3};
    vector<int> d = {3, 3, 3};
    vector<int> expected = {1, 2, 3};

    test_jim_solution(t, d, expected);
}

void test_hr_sample1() 
{
    vector<int> t = {8,4,5,3,4};
    vector<int> d = {1,2,6,1,3};
    vector<int> expected = {4,2,5,1,3};

    test_jim_solution(t, d, expected);
}

void hackerrank() {
    int n;
    cin >> n;

    vector<int> t(n);
    vector<int> d(n);

    for (size_t i=0; i<n; i++) {
        cin >> t[i] >> d[i];
    }

    vector<int> orders;
    jim_solution(t, d, orders);

    for (auto order: orders) {
        cout << order << " ";
    }
    cout << endl;
}

int main() {
    //hackerrank();
    test_hr_sample0();
    test_hr_sample1();
    //test_01();
    return 0;
}
