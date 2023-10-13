/*
https://www.hackerrank.com/challenges/bear-and-steady-gene

Design:
Find first letter distribution in the string 's'. Let's assume it is
    [a1, a2, a3, a4]

then we calculate how much these numbers differ from average 'm'
    [d1, d2, d3, d4]

now we need to find the smallest subsequence of string 's' that contains
at least dk number of letter lk (for k=1..4)

that is solution

How to build:
Linux: g++ --std=c++11 <file>.cpp
Windows (vcvarsall.bat): cl /EHsc <file>.cpp
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const bool DEBUG = true;

// d[i] - number of appeareances of letter L[i]
void dist_char(char c, vector<long> &d, int k) {
    if (c == 'A') {
        d[0] += k;
    } else if (c == 'C') {
        d[1] += k;
    } else if (c == 'G') {
        d[2] += k;
    } else {
        d[3] += k;
    }
}

void find_letter_distribution(const string &s, vector<long> &dist)
{
    for (char c: s) {
        dist_char(c, dist, 1);
    }

    long average = s.size() / 4;

    for (int i=0; i<dist.size(); ++i) {
        dist[i] = max(dist[i]-average, 0L);
    }
}

bool is_solution(const vector<long> &ss_dist, const vector<long> &dist) {
    for (int i=0; i<dist.size(); ++i) {
        if (ss_dist[i] < dist[i]) {
            return false;
        }
    }

    return true;
}

long find_minimum_sub(const string &s)
{
    vector<long> dist(4, 0);
    find_letter_distribution(s, dist);

    vector<long> substring_dist(4, 0);
    long i = 0;
    long j = 0;

    long abs_min_length = dist[0]+dist[1]+dist[2]+dist[3];
    long min_length = s.size();

    while (i < s.size()-abs_min_length && j < s.size()) {
        if (DEBUG) cout << "i=" << i << ", j=" << j << endl;
        dist_char(s[j], substring_dist, 1);

        while (is_solution(substring_dist, dist)) {
            if (DEBUG) cout << "solution: " << s.substr(i, j-i+1) << endl;
            if (j-i+1 < min_length) {
                min_length = j-i+1;
            }

            dist_char(s[i], substring_dist, -1);
            i++;
        }

        j++;
    }

    return min_length;
}

void tc_hr_sample()
{
    string s = "GAAATAAA";
    cout << find_minimum_sub(s) << endl;
}

void hackerrank()
{
    long n;
    cin >> n;

    string s;
    cin >> s;

    cout << find_minimum_sub(s) << endl;
}

int main() {
    //hackerrank();
    tc_hr_sample();
    return 0;
}

