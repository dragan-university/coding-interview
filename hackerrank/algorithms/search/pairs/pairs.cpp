/*
https://www.hackerrank.com/challenges/pairs
*/

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
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int pairs(vector < int > a,int k) {
   int ans = 0;

    sort(a.begin(), a.end());
    size_t i = 0;
    size_t j = 1;
    while (j < a.size()) {
        int d = a[j] - a[i];
        if (d == k) {
            ans++;
            i++;
            j++;
        } else if(d < k) {
            j++;
        } else {
            i++;
        }
    }

    return ans;
}

void test_pairs(vector<int> &a, int k, int expected)
{
    int actual = pairs(a, k);

    if (actual == expected) {
        cout << "PASS";
    } else {
        cout << "FAIL - actual=" << actual << " expected=" << expected;
    }
    cout << endl;
}

void tc_hr_sample()
{
    vector<int> a = {1,5,3,4,2};
    test_pairs(a, 2, 3);
}

void tc_my_01()
{
    vector<int> a = {1,5,3,4,2};
    test_pairs(a, 3, 2);
}

void hackerrank()
{
    int res;

    int _a_size,_k;
    cin >> _a_size>>_k;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }

    res = pairs(_a,_k);
    cout << res;
}

int main() {

    //hackerrank();
    tc_hr_sample();
    tc_my_01();
    return 0;
}
