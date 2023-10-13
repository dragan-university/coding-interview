#!/bin/python3
"""
https://www.hackerrank.com/challenges/equal

Analisys:
Solve inverse problem that has equiualent solution: take from a single person
1, 2 or 5 chocolates until they all have the same number of chocolates
"""
DEBUG = True

def steps_to_reach_equal(equal_chocolates_count, chocolates_count):
    """
    Calculates and returns number of steps to go from 'chocolates_count' to
    'equal_chocolates_count'
    """
    chocolates_diff = chocolates_count - equal_chocolates_count
    steps_count = int(chocolates_diff / 5)
    chocolates_diff = chocolates_diff % 5
    steps_count += int(chocolates_diff / 2)
    steps_count += chocolates_diff % 2

    return steps_count

def equalize_chocolates(chocolates_distribution):
    """
    implements solution
    """
    min_chocolates = min(chocolates_distribution)
    if DEBUG: print('min_chocolates: {}'.format(min_chocolates))

    required_steps = [0, 0, 0]
    for chocolates_count in chocolates_distribution:
        if DEBUG: print('chocolates_count: {}'.format(chocolates_count))
        equal_chocolates_count = min_chocolates
        required_steps[0] += steps_to_reach_equal(equal_chocolates_count, chocolates_count)
        equal_chocolates_count = min_chocolates - 1
        required_steps[1] += steps_to_reach_equal(equal_chocolates_count, chocolates_count)
        equal_chocolates_count = min_chocolates - 2
        required_steps[2] += steps_to_reach_equal(equal_chocolates_count, chocolates_count)
        if DEBUG: print('required_steps: {}'.format(required_steps))

    return min(required_steps)

def test_equalize_chocolates(distribution, expected_result):
    print('{} - expected {}'.format(distribution, expected_result))
    actual_result = equalize_chocolates(distribution)
    if actual_result == expected_result:
        print(" PASS")
    else:
        print(" FAIL: E:", expected_result, " A:", actual_result)

    print('')

def test_hr_sample():
    test_equalize_chocolates((2, 2, 3, 7), 2)

def test_001():
    test_equalize_chocolates((1, 2, 3, 4), 4)

def hr_testcase():
    N = input().strip()
    distribution = [int(chocolates) for chocolates in input().strip().split(' ')]
    print(equalize_chocolates(distribution))

def hackerrank():
    T = int(input().strip())

    for ix in range(T):
        hr_testcase()


#hackerrank()
test_hr_sample()
test_001()
