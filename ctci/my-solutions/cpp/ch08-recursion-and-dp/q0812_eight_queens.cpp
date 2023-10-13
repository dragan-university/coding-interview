/*
CTCI - Chapter 8 - Question 12

Eight Queens: Write an algorithm to print all ways of arranging eight Queens
on an 8x8 chess board so that none of them share the same row, column or
diagonal. In this case diagonal means all diagonals, not just the two that
bisect the board.

Solution:
Apply backtracking algorithm.

Example:

Build:

Linux & Mac:
    g++ <file.cpp> or
    g++ -std=c++11 <file.cpp>

Windows (vcvarsall.bat):
    cl /EHsc <file.cpp>
*/

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <ctime>

using namespace std;

const bool DEBUG = false;
const unsigned N = 8;

int get_position(int *board, unsigned i, unsigned j)
{
    return *(board+N*j+i);
}

void print_board(int *board)
{
    if (DEBUG) {
        for (unsigned i=0; i<N; ++i) {
            for (unsigned j=0; j<N; ++j) {
                cout << get_position(board, i, j) << ":";
            }
            cout << endl;
        }
        cout << endl;
    }
}

void print_solution(const vector<pair<unsigned, unsigned> > &solution)
{
    for (auto position: solution) {
        cout << "(" << position.first << "," << position.second << ") : ";
    }
    cout << endl;
}

bool is_position_free(int *board, unsigned i, unsigned j)
{
    return (*(board+N*j+i) == 0);
}

void set_position(int *board, unsigned i, unsigned j, int value)
{
    *(board+N*j+i) = value;
}

bool find_all_free_positions_on_board(
        int *board,
        vector<pair<unsigned, unsigned> > &free_positions)
{
    for (unsigned i=0; i<N; ++i) {
        for (unsigned j=0; j<N; ++j) {
            if (is_position_free(board, i, j)) {
                free_positions.push_back(make_pair(i, j));
            }
        }
    }
    return false;
}

void mark_positions_on_board_occupied(
        int *board, // in
        pair<unsigned, unsigned> &position, // in
        vector<pair<unsigned, unsigned> > &occupied_positions) // out
{
    for (unsigned i=0; i<N; ++i) {
        if (is_position_free(board, i, position.second)) {
            set_position(board, i, position.second, 1);
            occupied_positions.push_back(make_pair(i, position.second));
        }

        if (is_position_free(board, position.first, i)) {
            set_position(board, position.first, i, 1);
            occupied_positions.push_back(make_pair(position.first, i));
        }
    }

    int i = position.first + 1;
    int j = position.second + 1;
    while (i<N && j<N) {
        if (is_position_free(board, i, j)) {
            set_position(board, i, j, 1);
            occupied_positions.push_back(make_pair(i, j));
        }

        i++;
        j++;
    }

    i = position.first - 1;
    j = position.second - 1;
    while (i>=0 && j>=0) {
        if (is_position_free(board, i, j)) {
            set_position(board, i, j, 1);
            occupied_positions.push_back(make_pair(i, j));
        }

        i--;
        j--;
    }

    i = position.first - 1;
    j = position.second + 1;
    while (i>=0 && j<N) {
        if (is_position_free(board, i, j)) {
            set_position(board, i, j, 1);
            occupied_positions.push_back(make_pair(i, j));
        }

        i--;
        j++;
    }

    i = position.first + 1;
    j = position.second - 1;
    while (i<N && j>=0) {
        if (is_position_free(board, i, j)) {
            set_position(board, i, j, 1);
            occupied_positions.push_back(make_pair(i, j));
        }

        i++;
        j--;
    }
}

void backtrack_positions(
        int *board,
        vector<pair<unsigned, unsigned> > &positions)
{
    for (auto position: positions) {
        set_position(board, position.first, position.second, 0);
    }
}

bool eight_queens(
        int *board,
        vector<pair<unsigned, unsigned> > &solution)
{
    print_board(board);
    if (solution.size() == N) {
        return true;
    }

    vector<pair<unsigned, unsigned> > free_positions;
    find_all_free_positions_on_board(board, free_positions);

    for (auto position: free_positions) {
        solution.push_back(position);
        if (DEBUG) print_solution(solution);
        vector<pair<unsigned, unsigned> > occupied_positions;
        mark_positions_on_board_occupied(board, position, occupied_positions);
        if (eight_queens(board, solution)) {
            return true;
        } else {
            backtrack_positions(board, occupied_positions);
            solution.pop_back();
        }
    }

    return false;
}

int main()
{
    int board[N][N] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
    };

    vector<pair<unsigned, unsigned> > solution;
    eight_queens((int *)board, solution);

    cout << solution.size() << endl;
    print_solution(solution);

    return 0;
}
