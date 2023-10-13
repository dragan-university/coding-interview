#!/usr/local/bin/python
#  -*- coding: utf-8 -*-
"""
http://www.geeksforgeeks.org/maximum-path-sum-triangle/
http://www.geeksforgeeks.org/dynamic-programming/

Maximum path sum in a triangle

We have given numbers in form of triangle, by starting at the top of the 
triangle and moving to adjacent numbers on the row below, find the maximum total 
from top to bottom.

Examples:

Input :
   3
  7 4
 2 4 6
8 5 9 3
Output : 23
Explanation : 3 + 7 + 4 + 9 = 23

Input :
   8
 -4 4
 2 2 6
1 1 1 1
Output : 19
Explanation : 8 + 4 + 6 + 1 = 19
"""
DEBUG = False
RUN_ALL = True

def max_sum(triangle):
    """
    triangle example = [[3],[7,4],[2,4,6],[8,5,9,6]]
    """
    # start with last row
    row_index = len(triangle)-1
    while (row_index):
        # get last 2 rows
        row = triangle[row_index]
        prev_row = triangle[row_index-1]
        # update values in the row closer to the top
        for ix in range(len(prev_row)):
            prev_row[ix] += max(row[ix], row[ix+1])

        row_index -= 1

    # top of the triangle contains maximum sum :)
    return triangle[0][0]


def test_driver(triangle, expected_result):
    print('triangle = {}, max_sum = {}'.format(triangle, expected_result))
    _max_sum = max_sum(triangle)
    if _max_sum == expected_result:
        print('PASS')
    else:
        print('FAIL: E={}, A={}'.format(expected_result, _max_sum))
    
if RUN_ALL: test_driver([[3],[7,4],[2,4,6],[8,5,9,6]], 23)
if RUN_ALL: test_driver([[3],[7,4]], 10)
