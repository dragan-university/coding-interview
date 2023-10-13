#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int knightl_recursive(int i, int j, int n, int& moves_count, vector<vector<boolean> >& visited_positions) {
    if (i == n-1 && j == n-1) {
        return moves_count;
    }

    vector<pair<int, int> > possible_moves;
    determine_possible_moves(i, j, n, visited_positions);

    for(auto possible_move: possible_moves) {
        visited_positions[possible_move.first, possible_move.second] = true;
        moves_count++;
        knightl_recursive(possible_move.first, possible_move.second, n, moves_count, visited_positions);
    }
}

int knightl(int i, int j, int n) {
    int moves_count = 0;
    return knightl_recursive(i, j, n, moves_count);
}

int main(){
    int n;
    cin >> n;

    vector<vector<int> > solutions;
    for (int i=1; i<n; ++i) {
        vector<int> solutions_i;

        for (int j=i; j<n; ++j) {
            int s = knightl(i, j, n);
            solution_i.push_back(s);
        }

        solutions.push_back(solution_i);
    }
    // your code goes here
    return 0;
}
