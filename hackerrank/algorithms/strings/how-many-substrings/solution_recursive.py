#!/bin/python3
"""
https://www.hackerrank.com/challenges/how-many-substrings

Analisys:
We can apply recursive algorithm. Let's s(n) be solution for string s with n
chars c1,...,cn. Then s(n) = s(n-1) + all unique strings that end with cn
"""
# HACKERRANK DOES NOT HAVE sortedcontainers!!!
from sortedcontainers import SortedList

DEBUG = True

def how_many_substrings_r(s, substrings):
    """
    recursive helper function
    """
    if DEBUG: print('recursion: {}'.format(s))
    if len(s) == 1:
        substrings.add(s)
        return

    # check string without the last char
    how_many_substrings_r(s[:-1], substrings)

    # now check all substrings ending with last char
    for idx in range(len(s)):
        if DEBUG: print('check substring: {} - '.format(s[idx:]), end='')
        if s[idx:] not in substrings:
            if DEBUG: print('add')
            substrings.add(s[idx:])
        else:
            if DEBUG: print('-')

    if DEBUG: print('substrings: {}'.format(substrings))

def how_many_substrings(s, left, right):
    """
    implements solution
    """
    ss = s[left:right+1]
    if DEBUG: print('substring is {}'.format(ss))
    substrings = SortedList()
    how_many_substrings_r(ss, substrings)
    return len(substrings)

def test_how_many_substrings(s, left, right, expected_result):
    print('{}:{}-{} - expected {}'.format(s, left, right, expected_result))
    actual_result = how_many_substrings(s, left, right)
    if actual_result == expected_result:
        print(" PASS")
    else:
        print(" FAIL: E:", expected_result, " A:", actual_result)

    print('')

def test_hr_sample():
    test_how_many_substrings('aabaa', 1, 4, 8)

def hackerrank():
    n,q = input().strip().split(' ')
    n,q = [int(n),int(q)]
    s = input().strip()
    for a0 in range(q):
        left,right = input().strip().split(' ')
        left,right = [int(left),int(right)]
        print(how_many_substrings(s, left, right))

#hackerrank()
test_hr_sample()
