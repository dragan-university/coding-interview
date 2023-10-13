#!/bin/python3
"""
https://www.hackerrank.com/challenges/equal

Analisys:
This may be solved using DFS alghoritms
"""
import collections

DEBUG = False

def is_equal(distribution):
    """
    check if distribution is equal (ie. all people have same number of
    chocolates)
    """
    for person in range(len(distribution)-1):
        if distribution[person] != distribution[person+1]:
            return False

    return True

def add_chocolates(person_to_ignore, current_distribution, value_to_add):
    """
    add 'value_to_add' to all peopel in 'current_distribution' except to the
    person 'person_to_ignore'
    """
    # if DEBUG:
    #     print('add_chocolate({}, {}, {})'.format(
    #         person_to_ignore,
    #         current_distribution,
    #         value_to_add))

    new_distribution = [x for x in current_distribution]
    for person in range(len(current_distribution)):
        if person != person_to_ignore:
            new_distribution[person] += value_to_add

    return tuple(new_distribution)

def equalize_chocolates(distribution):
    """
    implements solution
    """
    if is_equal(distribution):
        return 0

    dd = {distribution: 0}
    dq = collections.deque([distribution])

    while dq:
        current_distribution = dq.popleft()
        if DEBUG: print('{} - {}'.format(current_distribution, dd[current_distribution]))

        for person_to_ignore in range(len(current_distribution)):
            for value_to_add in [1, 2, 5]:
                new_distribution = add_chocolates(
                    person_to_ignore,
                    current_distribution,
                    value_to_add)

                if is_equal(new_distribution):
                    if DEBUG: print('BINGO({},{}): {} - {}'.format(person_to_ignore, value_to_add, new_distribution, dd[current_distribution]+1))
                    return dd[current_distribution]+1
                else:
                    if new_distribution not in dd:
                        dd[new_distribution] = dd[current_distribution]+1
                        dq.append(new_distribution)

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
    T = input().strip()

    for ix in range(T):
        hr_testcase()


#hackerrank()
test_hr_sample()
test_001()
