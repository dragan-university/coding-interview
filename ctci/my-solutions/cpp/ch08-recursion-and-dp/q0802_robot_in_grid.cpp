/*
CTCI - Chapter 8 - Question 2

Robot in a Grid: Imagine arobot sitting on the upper left corner of grid with R
rows and C columns. The robot can only move in two directions, right and down,
but certain cells are 'off limit' such that the robot cannot step on them'.
Design an alghoritm to find a path for the robot from the top-left to the
bottom-right.

Example:

bool grid[3][4] = {
    {1, 1, 1, 1},
    {1, 0, 1, 1},
    {1, 1, 0, 1}
}

path1 = RRRDD
path2 = RRDRD

Solution:

void find_path(path, paths, r, c, grid) {
    if (r == R) && (c == C) {
        path += (r,c)
        paths.add(path)
        return
    } elif (grid[r,c] == 0) {
        return;
    } else {
        find_path(path, paths, r+1, c, grid)
        find_path(path, paths, r, c+1, grid)
    }
}

Build:

Linux & Mac:
    g++ <file.cpp> or
    g++ -std=c++11 <file.cpp>

Windows (vcvarsall.bat):
    cl /EHsc <file.cpp>
*/

#include <iostream>
#include <cassert>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

void find_path(
        const string &path,
        vector<string> &paths,
        unsigned row,
        unsigned col,
        vector<vector<int> > &grid)
{
    if (!paths.empty()) return;

    int rows = grid.size();
    int cols = grid[0].size();

    if ((row == rows-1) && (col == cols-1)) {
        paths.push_back(path);
        return;
    } else if ((row == rows) || (col == cols)) {
        return;
    } else if (grid[row][col] == 0) {
        return;
    } else {
        find_path(path+"R", paths, row, col+1, grid);
        find_path(path+"D", paths, row+1, col, grid);
    }
}

void test_find_path(vector<vector<int> > &grid, const string &expected_path)
{
    clock_t tstart;

    vector<string> paths;
    find_path("", paths, 0, 0, grid);

    for (auto &path: paths) {
        cout << path << ":";
    }
    cout << endl;

    assert(paths[0] == expected_path);
}

void test_01_01()
{
    vector<vector<int> > grid = {
        {1, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
    };

    test_find_path(grid, "RRRDD");
}

void test_01_02()
{
    vector<vector<int> > grid = {
        {1, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
    };

    test_find_path(grid, "RRDRD");
}

void test_02_01()
{
    vector<vector<int> > grid = {
        {1, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1},
    };

    test_find_path(grid, "RRRDDD");
}

int main()
{
    test_01_01();
    test_01_02();
    test_02_01();

    return 0;
}
