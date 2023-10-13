"""
Description
"""
import traceback

DEBUG_LEVEL = 10

def solution(the_string):
    letters = {}

    for c in the_string:
        if c in letters:
            letters[c] += 1
        else:
            letters[c] = 1

    count_odd = 0
    for letter in letters:
        if letters[letter] % 2:
            count_odd += 1

    if count_odd > 1:
        return False
    return True

def test_driver(data, expected):
    test_name = traceback.extract_stack(None, 2)[0][2]
    print('=== {} ==='.format(test_name))
    print('data: {}, expected: {}'.format(data, expected))

    actual = solution(data)
    if actual == expected:
        print('PASS')
    else:
        print('FAIL: actual={}'.format(actual))
    print()

def test_sample_01():
    test_driver('ivicc', True)

def test_sample_02():
    test_driver('civil', False)

test_sample_01()
test_sample_02()
