/*
Q 1.8

Write an algorithm such that if an element in an MxN matrix is 0, its entire row
and column are set to 0.
---
Examples:

Questions to ask:

Design:
solution 1:
- create new MxN matrix and set all values to 1 (let's call it 'flag' matrix)
- go through the original matrix and for each 0 set entire row and column to 0
  in the flag matrix
- go through the flag matrix and set corresponding elements to 0 in the original
  matrix

solution 2:
- instead of flag matrix just use two arrays, one to keep track about rows
  that should beset to 0, and another for columns.

Note: to save space for the flag matrix we could use bitfield 
*/
#include <stdio.h>
#include <string.h>

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

/*
complexity is O(mxn)
*/
void matrix_with_zeros(int* matrix, int m, int n) {
    int columns[n];
    int rows[m];

    for (int r=0; r<m; r++) {
        for (int c=0; c<n; c++) {
            if (*(matrix+r*n+c) == 0) {
                rows[r] = 0;
                columns[c] = 0;
            }
        }
    }

    for (int r=0; r<m; r++) {
        if (rows[r] == 0) {
            for (int c=0; c<n; c++) {
                *(matrix+r*n+c) = 0;
            }
        }
    }

    for (int c=0; c<n; c++) {
        if (columns[c] == 0) {
            for (int r=0; r<m; r++) {
                *(matrix+r*n+c) = 0;
            }
        }
    }
}

template<typename T> bool compare_matrix(T* a, T* b, int m, int n) {
    bool result = true;

    cout << "m=" << m << ", n=" << n << endl;

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            T av = *(a+i*n+j);
            T bv = *(b+i*n+j);
            cout << i << ":" << j << "= (" << av << ":" << bv << ")" << endl;
            if (av != bv) {
                cout << "different at: " << i << ":" << j << " (" << av << ":" << bv << ")" << endl;
                return false;
            }
        }
    }

    return true;
}

template<typename T> void print_matrix(T* matrix, int m, int n) {
    for (int i=0; i<m; i++) {
        cout << i << ":";
        for (int j=0; j<n; j++) {
            T v = *(matrix+i*n+j);
            cout << v << ",";
        }
        cout << endl;
    }
}

void test_solution(int* matrix, int m, int n, int* expected) {
    matrix_with_zeros(matrix, m, n);

    // if (memcmp(matrix, expected, m*n*sizeof(int)) == 0) {
    //     cout << "PASS" << endl;
    // } else {
    //     cout << "FAIL" << endl;
    // }

    if (compare_matrix<int>(matrix, expected, m, n)) {
        cout << "PASS" << endl;
    } else {
        cout << "FAIL" << endl;
    }
}

void test_3x3_001() {
    const int m = 5;
    const int n = 4;
    int matrix[m][n] = {
        {1,2,3,0},
        {1,0,3,4},
        {1,2,3,4},
        {1,0,3,4},
        {1,2,3,4}
     };
    int expected[m][n] = {
        {0,0,0,0},
        {0,0,0,0},
        {1,0,3,0},
        {0,0,0,0},
        {1,0,3,0}
     };

     print_matrix<int>((int*)matrix, m, n);
     print_matrix<int>((int*)expected, m, n);

     test_solution((int*)matrix, m, n, (int*) expected);
}

int main()
{
    test_3x3_001();
    return 0;
}
