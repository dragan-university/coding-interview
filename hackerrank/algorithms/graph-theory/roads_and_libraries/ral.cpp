/*
https://www.hackerrank.com/challenges/torque-and-development 
(this is correct link, just the name is different for some reason)

Discussion:
If cost of the library is not bigger then cost of the road just build library in every city.
Otherwise,
  Find all groups of connected cities
  In each group build one library, and build minumum number of roads to connect all cities in the group.
    If groups size is N then we need to build N-1 roads.

How to build:
Linux: g++ --std=c++11 <file>.cpp
Windows (vcvarsall.bat): cl /EHsc <file>.cpp
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <fstream>

using namespace std;

const bool DEBUG = true;

void dfs(
    long long city, // 0-based
    const vector<vector<long> >& adjacent_cities,
    vector<bool>& visited)
{
    for (auto adj_city: adjacent_cities[city]) {
        if (!visited[adj_city-1]) {
            visited[adj_city-1] = true;
            dfs(adj_city-1, adjacent_cities, visited);
        }
    }
}

long calculate_number_of_groups(
    long long n,
    const vector<pair<long, long> >& roads)
{
    vector<bool> visited(n);
    long number_of_groups = 0;
    vector<vector<long> > adjacency(n);

    for (auto road: roads) {
        adjacency[road.first-1].push_back(road.second);
        adjacency[road.second-1].push_back(road.first);
    }

    for (long long city=0; city<n; ++city) {
        if (visited[city]) {
            continue;
        }

        number_of_groups++;
        dfs(city, adjacency, visited);
    }

    return number_of_groups;
}

long long ral_solution(
    long long n,
    long long m,
    long long clib,
    long long croad,
    const vector<pair<long, long> >& roads)
{
    if (clib <= croad) {
        return clib*n;
    }

    long number_of_groups = calculate_number_of_groups(n, roads);
    return number_of_groups*clib + (n-number_of_groups)*croad;
}

void test_ral_solution(
    long n,
    long m,
    long clib,
    long croad,
    const vector<pair<long, long> >& roads,
    long long expected)
{
    cout << "=== begin test case: " << n << ":" << m << ":" << clib << ":" << croad << " ===" << endl;
    long long actual = ral_solution((long long)n, (long long)m, (long long)clib, (long long)croad, roads);
    if (DEBUG) cout << "actual=" << actual << endl;

    if (actual == expected) {
        cout << "PASS";
    } else {
        cout << "FAIL";
        if (DEBUG) cout << endl << "expected=" << expected << endl;
    }
    cout << endl;
}

void test_hr_sample1()
{
    long n = 3;
    long m = 3;
    long clib = 2;
    long croad = 1;
    vector<pair<long, long> > roads = {
        make_pair(1, 2),
        make_pair(2, 1),
        make_pair(2, 3),
    };

    long long expected = 4;

    test_ral_solution(n, m, clib, croad, roads, expected);
}

void test_hr_sample2()
{
    long n = 6;
    long m = 6;
    long clib = 2;
    long croad = 5;
    vector<pair<long, long> > roads = {
        make_pair(1, 3),
        make_pair(3, 4),
        make_pair(2, 4),
        make_pair(1, 2),
        make_pair(2, 3),
        make_pair(5, 6),
    };

    long long expected = 12;

    test_ral_solution(n, m, clib, croad, roads, expected);
}

void test_hr_01_1()
{
    long n = 9;
    long m = 2;
    long clib = 91;
    long croad = 84;
    vector<pair<long, long> > roads = {
        make_pair(8, 2),
        make_pair(2, 9),
    };

    long long expected = 805;

    test_ral_solution(n, m, clib, croad, roads, expected);
}

void test_hr_01_2()
{
    long n = 5;
    long m = 9;
    long clib = 92;
    long croad = 23;
    vector<pair<long, long> > roads = {
        make_pair(2, 1),
        make_pair(5, 3),
        make_pair(5, 1),
        make_pair(3, 4),
        make_pair(3, 1),
        make_pair(5, 4),
        make_pair(4, 1),
        make_pair(5, 2),
        make_pair(4, 2),
    };

    long long expected = 184;

    test_ral_solution(n, m, clib, croad, roads, expected);
}

void test_hr_01_4()
{
    long n = 1;
    long m = 0;
    long clib = 5;
    long croad = 3;
    vector<pair<long, long> > roads = {
    };

    long long expected = 5;

    test_ral_solution(n, m, clib, croad, roads, expected);
}

void test_hr_01_5()
{
    long n = 2;
    long m = 0;
    long clib = 102;
    long croad = 1;
    vector<pair<long, long> > roads = {
    };

    long long expected = 204;

    test_ral_solution(n, m, clib, croad, roads, expected);
}

void test_my_01()
{
    long n = 8;
    long m = 5;
    long clib = 2;
    long croad = 1;
    vector<pair<long, long> > roads = {
        make_pair(1, 3),
        make_pair(3, 2),
        make_pair(4, 5),
        make_pair(7, 8),
        make_pair(6, 8),
    };

    long long expected = 3*2+(8-3)*1;

    test_ral_solution(n, m, clib, croad, roads, expected);
}

const int RUN_ALL_TESTS = -1;

void test_from_file(ifstream &infile, ifstream &outfile, int this_test, int test_to_run)
{
    long long expected;
    outfile >> expected;

    long n;
    infile >> n;
    
    long m;
    infile >> m;

    long clib;
    infile >> clib;
    
    long croad;
    infile >> croad;

    vector<pair<long, long> > roads;
    long first;
    long second;
    for (size_t i=0; i<m; ++i) {
        infile >> first;
        infile >> second;
        roads.push_back(make_pair(first, second));
    }

    if (test_to_run == RUN_ALL_TESTS || this_test == test_to_run) {
        test_ral_solution(n, m, clib, croad, roads, expected);
    }
}

void tests_from_files(const string &input, const string &output, int test_to_run=RUN_ALL_TESTS)
{
  ifstream infile(input);
  ifstream outfile(output);
  
  int q;
  infile >> q;
  cout << "q=" << q << endl;

  for (int i=0; i<q; i++) {
    test_from_file(infile, outfile, i, test_to_run);
  }
}

void hr_query()
{
    long n;
    long m;
    long clib;
    long croad;

    cin >> n;
    cin >> m;
    cin >> clib;
    cin >> croad;

    vector<pair<long, long> > roads;
    for (size_t i=0; i<m; i++) {
        long first;
        long second;
        cin >> first;
        cin >> second;
        roads.push_back(make_pair(first, second));
    }
    if (DEBUG) cout << "n=" << n << ", m=" << m << endl;

    long long result = ral_solution(n, m, clib, croad, roads);
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
    // hackerrank();
    test_hr_sample1();
    test_hr_sample2();
    test_hr_01_1();
    test_hr_01_2();
    test_hr_01_4();
    test_hr_01_5();
    test_my_01();
    tests_from_files("input01.txt", "output01.txt", RUN_ALL_TESTS);
    tests_from_files("input04.txt", "output04.txt", RUN_ALL_TESTS);

    return 0;
}
