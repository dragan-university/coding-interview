#!/bin/python3
"""
https://www.hackerrank.com/challenges/reverse-shuffle-merge/problem


INCOMPLETE!

"""
import math
import os
import random
import re
import sys
from queue import PriorityQueue

DEBUG_LEVEL = 10

def findLettersDistribution(s):
    letterCounts = {}
    for letter in s:
        if letter in letterCounts:
            letterCounts[letter] += 1
        else:
            letterCounts[letter] = 1

    return letterCounts

def isLettersDistributionCorrect(letterCounts):
    print(letterCounts)
    for letter in letterCounts:
        if letterCounts[letter] % 2:
            return False
    
    return True

def constructStringFromLetterDistribution(s, letterCounts):
    a = ''
    q = PriorityQueue()
    letters = {}
    for letter in letterCounts:
        letterCounts[letter] /= 2
    rs = reversed(s)
    for c in rs:
        q.put(c)
        if not c in letters:
            letters[c] = 1
        elif letters[c] <= letterCounts[c]:
            letters[c] += 1
        else: # letters[c] == letterCounts[c]
            cq = q.get()
            a += cq
            if c != cq:
                a += c
                letters[c] = 0
            q = PriorityQueue() # reset priority queue

            if len(a) == len(s)/2:
                return a

# Complete the reverseShuffleMerge function below.
def reverseShuffleMerge(s):
    letters = findLettersDistribution(s)
    if not isLettersDistributionCorrect(letters):
        return 'impossible'

    return constructStringFromLetterDistribution(s, letters)
    
def test_reverseShuffleMerge(s, expected_result):
    print('{} - expected {}'.format(s, expected_result))
    actual_result = reverseShuffleMerge(s)
    if actual_result == expected_result:
        print(" PASS")
    else:
        print(" FAIL: E:", expected_result, " A:", actual_result)

    print('')

def test_hr_sample_0():
    test_reverseShuffleMerge('eggegg', 'egg')

def test_hr_sample_1():
    test_reverseShuffleMerge('abcdefgabcdefg', 'agfedcb')

def test_0():
    test_reverseShuffleMerge('abcabc', 'acb')

def test_1():
    test_reverseShuffleMerge('abcdabcd', 'adcb')

def hackerrank():
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = reverseShuffleMerge(s)

    fptr.write(result + '\n')

    fptr.close()

if __name__ == '__main__':
    #hackerrank()
    test_hr_sample_0()
    #test_hr_sample_1()
    #test_0()
    #test_1()
