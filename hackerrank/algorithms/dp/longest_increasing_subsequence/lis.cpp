/*
The Longest Increasin Subsequence
https://www.hackerrank.com/challenges/longest-increasing-subsequent

------------
Solution:
http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/

------------
Build:
Linux: g++ -std=c++11 <file>.cpp
Windows (vcvarsall.bat): cl /EHsc <file>.cpp




Is testcase #7 correct? The input is:
[10, 29471, 5242, 21175, 28931, 2889, 7275, 19159, 21773, 1325, 6901]
Expected output is 4, but the longest subsequence is 5, i.e.:
[10, 5242, 7275, 19159, 21773]
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

const int DEBUG = false;

void print_map_iv(const string &s, const map<int, vector<int> > &m)
{
    cout << s << "=";
    for (auto &e: m) {
        cout << e.first << "-";
        for (auto &i: e.second) {
            cout << i << ":";
        }
        cout << "***";
    }
    cout << endl;
}

void print_vector_i(const vector<int> &v) {
    cout << "v=";
    for (auto e: v) {
        cout << e << ":";
    }
    cout << endl;
}

// My solution
// does not pass all test cases
// e.g. tc 01
unsigned lis(const vector<int> &a)
{
    if (DEBUG) print_vector_i(a);
    map<int, vector<int> > active_lists = {{a[0], {a[0]}}};
    if (DEBUG) print_map_iv("active lists=", active_lists);

    for (unsigned i=1; i<a.size(); ++i) {
        if (DEBUG) cout << "check element " << a[i] << endl;

        if (a[i] < active_lists.begin()->first) {
            if (DEBUG) cout << "this is new smallest value" << endl;
            active_lists.erase(active_lists.begin());
            active_lists[a[i]] = {a[i]};
        } else if (a[i] > active_lists.rbegin()->first) {
            if (DEBUG) cout << "this is new biggest value" << endl;
            vector<int> v = active_lists.rbegin()->second;
            v.push_back(a[i]);
            active_lists[a[i]] = v;
        } else {
            if (DEBUG) cout << "in the middle" << endl;
            // replace the last element in the first active list which has biggest
            // element bigger then a[i]
            auto itup = active_lists.upper_bound(a[i]);
            vector<int> active_list = itup->second;
            *active_list.rbegin() = a[i];
            active_lists.erase(itup);
            active_lists[a[i]] = active_list;
        }

        if (DEBUG) print_map_iv("active lists=", active_lists);
    }

    return active_lists.rbegin()->second.size();
}

// HR solution
// Binary search
int get_ceil_index(
        const vector<int> &a,
        vector<int> &t,
        int l,
        int r,
        int key)
{
    while (r - l > 1)
    {
        int m = l + (r - l)/2;
        if (a[t[m]] >= key)
            r = m;
        else
            l = m;
    }

    return r;
}

int lis_hr(const vector<int> &a)
{
    if (a.empty()) {
        return 0;
    }

    vector<int> tail_indices(a.size(), 0); // Initialized with 0
    vector<int> prev_indices(a.size(), -1); // initialized with -1

    int len = 1; // it will always point to empty location
    for (int i=1; i<a.size(); i++)
    {
        if (a[i] < a[tail_indices[0]])
        {
            // new smallest value
            tail_indices[0] = i;
        }
        else if (a[i] > a[tail_indices[len-1]])
        {
            // a[i] wants to extend largest subsequence
            prev_indices[i] = tail_indices[len-1];
            tail_indices[len++] = i;
        }
        else
        {
            // a[i] wants to be a potential condidate of future subsequence
            // It will replace ceil value in tailIndices
            int pos = get_ceil_index(
                            a,
                            tail_indices,
                            -1,
                            len-1,
                            a[i]);

            prev_indices[i] = tail_indices[pos-1];
            tail_indices[pos] = i;
        }
    }

    if (DEBUG) {
        cout << "LIS of given input" << endl;
        for (int i=tail_indices[len-1]; i>=0; i=prev_indices[i])
            cout << a[i] << " ";
        cout << endl;
    }

    return len;
}

void test_lis(const vector<int> &a, unsigned expected_result)
{
    unsigned actual_result = 0;

    cout << "my solution" << endl;
    clock_t tstart = clock();
    actual_result = lis(a);
    cout << "Time taken: " << (double)((clock() - tstart)/CLOCKS_PER_SEC) << endl;

    cout << "E:" << expected_result << " A:" << actual_result;
    if (actual_result == expected_result) {
        cout << " PASS";
    } else {
        cout << " FAIL";
    }
    cout << endl;

    cout << "HR solution" << endl;
    tstart = clock();
    actual_result = lis_hr(a);
    cout << "Time taken: " << (double)((clock() - tstart)/CLOCKS_PER_SEC) << endl;

    cout << "E:" << expected_result << " A:" << actual_result;
    if (actual_result == expected_result) {
        cout << " PASS";
    } else {
        cout << " FAIL";
    }
    cout << endl;
}

void test_hr_sample()
{
    vector<int> a = {5,2,7,4,3,8};

    test_lis(a, 3);
}

void test_my_01()
{
    vector<int> a = {5,2,7,4,3,5};

    test_lis(a, 3);
}

void hackerrank()
{
    int N;

    cin >> N;

    vector<int> a(N);

    for (int i=0; i<N; i++) {
        cin >> a[i];
    }

    int result = lis(a);
    cout << result << endl;
}

int main()
{
  //hackerrank();
  test_hr_sample();
  test_my_01();
  return 0;
}
