/*
Find the minimum number of moves needed to move from one cell of matrix to 
another

Given a N X N matrix (M) filled with 1, 0, 2, 3. Find the minimum numbers of 
moves needed to move from source to destination while traversing through blank 
cells only. You can traverse up, down, right and left.

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Blank Wall.

Note : there is only single source and single destination. there may be more 
than one path from source to destination each move in matrix we consider as ‘1’

Build:
Linux & Mac:
    g++ <file.cpp> or
    g++ --std=c++11 <file.cpp>

Windows (vcvarsall.bat):
    cl /EHsc <file.cpp>
*/

#include <iostream>
#include <vector>

using namespace std;

void find_end_points(
        vector<vector<int> > &M,
        pair<int, int> &start_point,
        pair<int, int> &end_point)
{
    for (size_t row=0; row<M.size(); ++row) {
        for (size_t col=0; col<M[0].size(); ++col) {
            if (M[row][col] == 1) {
                start_point.first = row;
                start_point.second = col;
            }

            if (M[row][col] == 2) {
                end_point.first = row;
                end_point.second = col;
            }

            if (start_point.first != -1 && end_point.first != -1) {
                return;
            }
        }
    }
}

bool is_end_reached(
        vector<vector<int> > &M,
        int row,
        int col,
        vector<pair<int, int> > &qnext)
{
    if (
            row >= 0 && row < M.size() &&
            col >= 0 && col < M[0].size()) {

        if (M[row][col] == 2) {
            return true;
        }

        if (M[row][col] == 3) {
            qnext.push_back(make_pair(row, col));
            M[row][col] = 4;  // mark visited
            return false;
        }
    }

    return false;
}

int find_shortest_path(
        vector<vector<int> > &M,
        pair<int, int> &start_point,
        pair<int, int> &end_point)
{
    vector<pair<int, int> > qcurrent = {start_point};
    vector<pair<int, int> > qnext;
    int path_length = 1;

    while (!qcurrent.empty()) {
        for (auto &pos: qcurrent) {
            if (is_end_reached(M, pos.first+1, pos.second, qnext)) {
                return path_length;
            }
            if (is_end_reached(M, pos.first-1, pos.second, qnext)) {
                return path_length;
            }
            if (is_end_reached(M, pos.first, pos.second+1, qnext)) {
                return path_length;
            }
            if (is_end_reached(M, pos.first, pos.second-1, qnext)) {
                return path_length;
            }
        }

        qcurrent = qnext;
        qnext.erase(qnext.begin(), qnext.end());
        path_length++;
    }

    return -1;
}

int find_shortest_path(vector<vector<int> > &M)
{
    pair<int, int> start_point(-1, -1);
    pair<int, int> end_point(-1, -1);
    find_end_points(M, start_point, end_point);

    return find_shortest_path(M, start_point, end_point);
}

void test_find_shortest_path(
        vector<vector<int> > &M,
        unsigned expected_result)
{
    unsigned actual_result = find_shortest_path(M);

    if (actual_result == expected_result) {
        cout << "PASS";
    } else {
        cout << "FAIL (expected=" << expected_result << " actual=" << actual_result << ")";
    }
    cout << endl;
}

void test_00()
{
    vector<vector<int> > M = {
        {0,3,2},
        {3,3,0},
        {1,3,0}
    };

    test_find_shortest_path(M, 4);
}

void test_01()
{
    vector<vector<int> > M = {
        {3,3,1,0},
        {3,0,3,3},
        {2,3,0,3},
        {0,3,3,3}
    };

    test_find_shortest_path(M, 4);
}

void test_02()
{
    vector<vector<int> > M = {
        {3,3,1,0},
        {0,0,3,3},
        {2,3,0,3},
        {0,3,3,3}
    };

    test_find_shortest_path(M, 8);
}

int main()
{
    test_00();
    test_01();
    test_02();

    return 0;
}
