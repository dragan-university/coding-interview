/*
https://www.hackerrank.com/challenges/spies-revised

Discussion:
This problem is similar to 8-queens. It has some additional contraints.


How to build:
Linux: g++ --std=c++11 <file>.cpp
Windows (vcvarsall.bat): cl /EHsc <file>.cpp
*/

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <ctime>

using namespace std;

const bool DEBUG = false;
const char FREE = ' ';
const char SPY = 'o';
const char OCCUPIED = '-';

char get_position(const vector<vector<char> >& board, unsigned i, unsigned j)
{
    return board[i][j];
}

void print_board(const vector<vector<char> >& board)
{
    for (unsigned i=0; i<board.size(); ++i) {
        for (unsigned j=0; j<board.size(); ++j) {
            cout << get_position(board, i, j) << " ";
        }
        cout << endl;
    }
    cout << endl;

    int x;
    cin >> x;
}

void print_solution(const vector<pair<unsigned, unsigned> >& solution)
{
    for (auto position: solution) {
        cout << "(" << position.first << "," << position.second << ") : ";
    }
    cout << endl;
}

bool is_position_free(
    vector<vector<char> >& board,
    unsigned i,
    unsigned j)
{
    return (board[i][j] == FREE);
}

void set_position(
    vector<vector<char> >& board,
    unsigned i,
    unsigned j,
    char value)
{
    board[i][j] = value;
}

bool find_all_free_positions_on_board(
        vector<vector<char> >& board,  // in
        vector<pair<unsigned, unsigned> >& free_positions)  // out
{
    for (unsigned i=0; i<board.size(); ++i) {
        for (unsigned j=0; j<board.size(); ++j) {
            if (is_position_free(board, i, j)) {
                free_positions.push_back(make_pair(i, j));
            }
        }
    }
    return false;
}

// trbl = top-right to bottom-left
void mark_trbl_diagonal_fields(
        vector<vector<char> >& board, // in
        pair<unsigned, unsigned>& position, // in
        vector<pair<unsigned, unsigned> >& new_occupied_fields) // out
{
    // position to bottom left
    int i = position.first - 1;
    int j = position.second + 1;
    while (i>=0 && j<board.size()) {
        if (is_position_free(board, i, j)) {
            set_position(board, i, j, OCCUPIED);
            new_occupied_fields.push_back(make_pair(i, j));
        }

        i--;
        j++;
    }

    // position to top right
    i = position.first + 1;
    j = position.second - 1;
    while (i<board.size() && j>=0) {
        if (is_position_free(board, i, j)) {
            set_position(board, i, j, OCCUPIED);
            new_occupied_fields.push_back(make_pair(i, j));
        }

        i++;
        j--;
    }
}

// tlbr = top-left to bottom-right
void mark_tlbr_diagonal_fields(
        vector<vector<char> >& board, // in
        pair<unsigned, unsigned>& position, // in
        vector<pair<unsigned, unsigned> >& new_occupied_fields) // out
{
    // position to bottom right
    int i = position.first + 1;
    int j = position.second + 1;
    while (i<board.size() && j<board.size()) {
        if (is_position_free(board, i, j)) {
            set_position(board, i, j, OCCUPIED);
            new_occupied_fields.push_back(make_pair(i, j));
        }

        i++;
        j++;
    }

    // position to top left
    i = position.first - 1;
    j = position.second - 1;
    while (i>=0 && j>=0) {
        if (is_position_free(board, i, j)) {
            set_position(board, i, j, OCCUPIED);
            new_occupied_fields.push_back(make_pair(i, j));
        }

        i--;
        j--;
    }
}

void mark_horizontal_and_vertical_fields(
        vector<vector<char> >& board, // in
        pair<unsigned, unsigned>& position, // in
        vector<pair<unsigned, unsigned> >& new_occupied_fields) // out
{
    for (unsigned i=0; i<board.size(); ++i) {
        if (is_position_free(board, i, position.second)) {
            set_position(board, i, position.second, OCCUPIED);
            new_occupied_fields.push_back(make_pair(i, position.second));
        }

        if (is_position_free(board, position.first, i)) {
            set_position(board, position.first, i, OCCUPIED);
            new_occupied_fields.push_back(make_pair(position.first, i));
        }

        set_position(board, position.first, position.second, SPY);
    }
}

void mark_new_occupied_fields_on_board(
        vector<vector<char> >& board, // in
        pair<unsigned, unsigned>& position, // in
        vector<pair<unsigned, unsigned> >& new_occupied_fileds) // out
{
    mark_horizontal_and_vertical_fields(
        board,
        position,
        new_occupied_fileds);

    mark_tlbr_diagonal_fields(
        board,
        position,
        new_occupied_fileds);

    mark_trbl_diagonal_fields(
        board,
        position,
        new_occupied_fileds);
}

void backtrack_positions(
        vector<vector<char> >& board,
        vector<pair<unsigned, unsigned> > &positions)
{
    for (auto position: positions) {
        set_position(board, position.first, position.second, FREE);
    }
}

bool find_spies_revised_solution(
        vector<vector<char> >& board,
        vector<pair<unsigned, unsigned> > &solution)
{
    if (DEBUG) print_board(board);
    if (solution.size() == board.size()) {
        return true;
    }

    vector<pair<unsigned, unsigned> > free_positions;
    find_all_free_positions_on_board(board, free_positions);

    for (auto position: free_positions) {
        solution.push_back(position);
        set_position(board, position.first, position.second, SPY);
        if (DEBUG) print_solution(solution);
        vector<pair<unsigned, unsigned> > new_occupied_positions;
        mark_new_occupied_fields_on_board(board, position, new_occupied_positions);

        if (find_spies_revised_solution(board, solution)) {
            return true;
        } else {
            set_position(board, position.first, position.second, FREE);
            backtrack_positions(board, new_occupied_positions);
            solution.pop_back();
        }
    }

    return false;
}

void init_board(vector<vector<char> >& board, int board_size)
{
    for(int i=0; i<board_size; ++i) {
        vector<char> row(board_size, FREE);
        board.push_back(row);
    }
}

void find_solution(int board_size)
{
    vector<vector<char> > board;
    init_board(board, board_size);

    vector<pair<unsigned, unsigned> > solution;
    if (find_spies_revised_solution(board, solution)) {
        print_solution(solution);
        print_board(board);
    } else {
        cout << "no solution" << endl;
    }
}

int main()
{
    find_solution(13);

    return 0;
}
