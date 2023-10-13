"""
demo
"""
DEBUG_LEVEL = 7

def solution(A):
    mA = {}
    for x in A:
        mA[x] = True

    for x in range(1,len(A)+1):
        if x not in mA:
            return x

    return len(A)+1

def test_driver(A, expected_result):
    print('A: {}, expected: {}'.format(A, expected_result))

    actual_result = solution(A)
    if (actual_result == expected_result):
        print('PASS')
    else:
        print('FAIL: actual={}'.format(actual_result))

def test_sample():
    test_driver([1,3,6,4,1,2], 5)

def test_01():
    test_driver([-1,-3], 1)

def test_02():
    test_driver([1,2,3], 4)

test_sample()
test_01()
test_02()