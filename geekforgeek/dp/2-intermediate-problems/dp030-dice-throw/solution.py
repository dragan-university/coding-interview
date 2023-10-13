#!/usr/local/bin/python
#  -*- coding: utf-8 -*-
"""
http://www.geeksforgeeks.org/dice-throw-problem/
http://www.geeksforgeeks.org/dynamic-programming/

Dice throw

Given n dice each with m faces, numbered from 1 to m, find the number of ways to 
get sum X. X is the summation of values on each face when all the dice are 
thrown.

Analisys:

sum(n,m,x) = 0, x<n or x>n*m
sum(n,m,n) = 1
sum(1,m,x) = 1, x<=m
sum(1,m,x) = 0, x>m
sum(n,m,x) = sum(n-1,m,x-1) + sum(n-1,m,x-2) + ... + sum(n-1,m,x-m)

m=6
n|x  1   2   3   4   5   6   7   8   9
1    1   1   1   1   1   1   0   0   0
2    0   1   2   3   4   5   6   5   4
3    0   0   1   3   6  10  15  21  25
4    0   0   0   1   4  10  20  35  56
5    0   0   0   0   1   5  15  35  70
"""
DEBUG = True
RUN_ALL = True

def print_table(table, message='==='):
    print(message)
    for i in range(len(table)):
        for j in range(len(table[i])):
            print('{:3d}:'.format(table[i][j]), end='')
        
        print()
    print()

def sum_count(n, m, x):
    """
    n - number of dices
    m - number of dice sides
    x - sum to find
    """
    # Create a table to store results of subproblems.  One extra 
    # row and column are used for simpilicity (number of dice
    # is directly used as row index and sum is directly used
    # as column index). The entries in 0th row and 0th column
    # are never used.
    sum_table = [[0 for i in range(x+1)] for j in range(n+1)]
    if DEBUG: print_table(sum_table, 'init table')

    for i in range(1, min(x,m)+1):
        sum_table[1][i] = 1

    if DEBUG: print_table(sum_table, 'init for 1 dice')

    for i in range(2, n+1):
        for j in range(1, x+1):
            for k in range(max(j-m, 1), j):
                sum_table[i][j] += sum_table[i-1][k]

    if DEBUG: print_table(sum_table, 'final')

    return sum_table[n][x]


def test_driver(n, m, x, expected_result):
    print('n = {}, m = {}, x={}, result={}'.format(n, m, x, expected_result))
    _sum_count = sum_count(n, m, x)
    if _sum_count == expected_result:
        print('PASS')
    else:
        print('FAIL: E={}, A={}'.format(expected_result, _sum_count))
    
if RUN_ALL: test_driver(3, 6, 8, 21)
if RUN_ALL: test_driver(3, 4, 5, 6)
