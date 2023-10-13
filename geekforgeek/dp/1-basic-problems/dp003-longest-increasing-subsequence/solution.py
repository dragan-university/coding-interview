#!/usr/local/bin/python
#  -*- coding: utf-8 -*-
"""
https://www.geeksforgeeks.org/longest-common-substring-dp-29/
http://www.geeksforgeeks.org/dynamic-programming/

Longest Increasing Subsequence | DP-3
We have discussed Overlapping Subproblems and Optimal Substructure properties.

Let us discuss Longest Increasing Subsequence (LIS) problem as an example problem that can be solved
using Dynamic Programming.
The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of
a given sequence such that all elements of the subsequence are sorted in increasing order. For 
example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is 
{10, 22, 33, 50, 60, 80}.
"""
DEBUG = False
RUN_ALL = True

def lis(a):
    """
    Time complexity: O(n), where n = len(a)
    Space complexity: O(n)
    """
    iss_tops = []
    iss_order = []

    for x in a:
        i = 0
        while i < len(iss_order):
            if x > iss_tops[iss_order[i]][1]:
                iss_tops[iss_order[i]][0] += 1
                iss_tops[iss_order[i]][1] = x

                j = i
                while j > 0 and iss_tops[iss_order[j]][0] > iss_tops[iss_order[j-1]][0]:
                    iss_order[j], iss_order[j-1] = iss_order[j-1], iss_order[j]
                    j -= 1

                break

            i += 1

        if i == len(iss_order):
            iss_tops.append([1, x])
            iss_order.append(i)

        print("e={}, iss_tops={}, iss_order={}".format(x, iss_tops, iss_order))

    return iss_tops[iss_order[0]][0]

def test_driver(a, expected_result):
    print('a = {}, result={}'.format(a, expected_result))
    actual_result = lis(a)
    if actual_result == expected_result:
        print('PASS')
    else:
        print('FAIL: E={}, A={}'.format(expected_result, actual_result))
    
if RUN_ALL: test_driver([10, 22, 9, 33, 21, 50, 41, 60, 80, 24], 6)
if RUN_ALL: test_driver([10, 22, 9, 33, 21, 50, 41, 60, 80, 24, 1, 2, 3, 4, 5, 6, 7], 7)
if RUN_ALL: test_driver([10, 9, 8, 1, 2], 2)
