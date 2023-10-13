#!/bin/python3
"""
https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem

2019-04-06: submitted but failed a few test cases due to too long time execution.
One way to improve it is to use binary search when checking rank.
For that we can use bisect python module.
Problem is it works only on arrays sorted in ascending order and scores are in desc order.
We could create new scrores in asc order.
Or implement our own bisect as explained in this article: https://stackoverflow.com/questions/29045162/binary-search-of-reversed-sorted-list-in-python

"""
import math
import os
import random
import re
import sys
import bisect

DEBUG_LEVEL = 10

def remove_duplicates_from_scores(scores):
    unique_scores = []
    last_score = None
    for score in scores:
        if (score != last_score):
            unique_scores.append(score)
            last_score = score

    #print ("unique {}".format(unique_scores))
    return unique_scores

def find_alice_rank(scores, last_rank, alice_score):
    rank = last_rank
    for score in scores[:last_rank]:
        if alice_score >= score:
            return rank
        rank += 1
    return rank

# Complete the climbingLeaderboard function below.
def climbingLeaderboard(scores, alice):
    result = []

    scores = remove_duplicates_from_scores(scores)

    rank = 0
    for alice_score in alice:
        rank = find_alice_rank(scores, rank, alice_score)
        result.append(rank)

    return result


def test_climbingLeaderboard(scores, alice, expected_result):
    print('{}-{} - expected {}'.format(scores, alice, expected_result))
    actual_result = climbingLeaderboard(scores, alice)
    if actual_result == expected_result:
        print(" PASS")
    else:
        print(" FAIL: E:", expected_result, " A:", actual_result)

    print('')

def test_hr_sample_1():
    test_climbingLeaderboard([100,100,50,40,40,20,10], [5,25,50,120], [6,4,2,1])

def hackerrank():
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    scores_count = int(input())

    scores = list(map(int, input().rstrip().split()))

    alice_count = int(input())

    alice = list(map(int, input().rstrip().split()))

    result = climbingLeaderboard(scores, alice)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()

if __name__ == '__main__':
    #hackerrank()
    test_hr_sample_1()
