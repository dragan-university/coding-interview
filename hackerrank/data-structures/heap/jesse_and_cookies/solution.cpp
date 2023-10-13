/*
https://www.hackerrank.com/challenges/jesse-and-cookies
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

const bool DEBUG = false;

int main() {
    long N;
    cin >> N;
    long K;
    cin >> K;
    priority_queue<long, vector<long>, greater<long> > A;
    for (size_t i=0; i<N; ++i) {
        int t;
        cin >> t;
        A.push(t);
    }

    if (A.empty()) {
        cout << "-1" << endl;
        return -1;
    }

    long counter = 0;
    while (!A.empty()) {
        long c1 = A.top();
        if (DEBUG) cout << c1 << endl;
        if (c1 >= K) {
            cout << counter << endl;
            return 0;
        }
        A.pop();

        if (A.empty()) {
            cout << "-1" << endl;
            return -1;
        }

        long c2 = A.top();
        A.pop();

        A.push(c1 + 2*c2);
        counter++;
    }

    return 0;
}
