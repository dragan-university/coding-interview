"""
odd-occurences-in-array
"""
DEBUG_LEVEL = 10

def solution(A):
    dA = {}
    for x in A:
        if x in dA:
            del dA[x]
        else:
            dA[x] = True

    dkeys = list(dA.keys())
    if DEBUG_LEVEL>5: print('values = {}'.format(dkeys))
    return dkeys[0]

def test_driver(A, expected_result):
    print('A: {}, expected: {}'.format(A, expected_result))

    actual_result = solution(A)
    if (actual_result == expected_result):
        print('PASS')
    else:
        print('FAIL: actual={}'.format(actual_result))

def test_sample():
    test_driver([9,3,9,3,9,7,9], 7)

test_sample()
