/*
https://www.hackerrank.com/challenges/journey-to-the-moon

The member states of the UN are planning to send 2 people to the Moon. But there 
is a problem. In line with their principles of global unity, they want to pair 
astronauts of 2 different countries.

There are N trained astronauts numbered from 0 to N-1. But those in charge of 
the mission did not receive information about the citizenship of each astronaut. 
The only information they have is that some particular pairs of astronauts 
belong to the same country.

Your task is to compute in how many ways they can pick a pair of astronauts 
belonging to different countries. Assume that you are provided enough pairs to 
let you identify the groups of astronauts even though you might not know their 
country directly. For instance, if 1,2,3 are astronauts from the same country; 
it is sufficient to mention that (1,2) and (2,3) are pairs of astronauts from 
the same country without providing information about a third pair (1,3).

Analisys:
- first find how many are there countries and astronauts per country. If we create
  a graph where two people are connected if they are from the same country we can
  use DFS alghoritm to find this info
- then for each pair of countris there are c1*c2 possibilities, where c1 is the
  number of astrounauts from the first ountry and c2 number of astronauts from
  the second country
- sum of all these nubers is the total number of possible combinations

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
    long person, // 0-based
    const vector<vector<long> >& people_from_same_country,  // 0-based
    vector<bool>& visited,
    long& group_size)
{
    for (auto person_from_same_country: people_from_same_country[person]) {
        if (!visited[person_from_same_couuntry]) {
            visited[person_from_same_couuntry] = true;
            if (DEBUG) cout << "add person " << person_from_same_country << endl;
            group_size++;
            dfs(person_from_same_country, people_from_same_country, visited, group_size);
        }
    }
}

void calculate_group_sizes(
    long N,
    const vector<pair<long, long> >& pairs_from_same_country,
    vector<long>& group_sizes)
{
    vector<bool> visited(N);

    vector<vector<long> > adjacency(N);
    for (auto pair_from_same_country: pairs_from_same_country) {
        adjacency[pair_from_same_country.first].push_back(pair_from_same_country.second);
        adjacency[pair_from_same_country.second].push_back(pair_from_same_country.first);
    }

    for (long person=0; person<N; ++person) {
        if (visited[person]) {
            continue;
        }

        visited[person] = true;
        long group_size = 1;
        dfs(person, adjacency, visited, group_size);
        if (DEBUG) cout << "person " << person << " group is " << group_size << endl;
        group_sizes.push_back(group_size);
    }
}

long count_ways(
    long N,
    const vector<pair<long, long> >& pairs_from_same_country)
{
    vector<long> group_sizes;
    calculate_group_sizes(N, pairs_from_same_country, group_sizes);

    long sum = 0;
    long result = 0;
    for (size_t i=0; i<group_sizes.size(); ++i) {
        result += sum*group_sizes[i];
        sum += group_sizes[i];
    }
    return result;
}

void test_count_ways(
    long N,
    const vector<pair<long, long> >& pairs_from_same_country,
    long expected)
{
    cout << "=== begin test case: " << N << ":" << pairs_from_same_country.size() << " ===" << endl;
    long actual = solution(N, pairs_from_same_country);
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
    long N = 5;
    vector<pair<long, long> > pairs_from_same_country = {
        make_pair(0, 1),
        make_pair(2, 3),
        make_pair(0, 4),
    };

    long expected = 6;

    test_solution(N, pairs_from_same_country, expected);
}

void test_hr_sample2()
{
    long N = 4;
    vector<pair<long, long> > pairs_from_same_country = {
        make_pair(0, 2),
    };

    long expected = 5;

    test_solution(N, pairs_from_same_country, expected);
}

void hackerrank()
{
    int N;
    cin >> N;

    int P;
    cin >> P;
    
    long a1;
    long a2;
    vector<pair<long, long> > pairs_from_same_country;
    for (size_t i=0; i<P; i++) {
        cin >> a1;
        cin >> a2;

        pairs_from_same_country.push_back(make_pair(a1, a2)); 
    }

    long result = solution(N, pairs_from_same_country);
    cout << result << endl;
}

int main() {
    // hackerrank();
    test_hr_sample1();
    test_hr_sample2();

    return 0;
}
