"""
3 - highest product of 3
"""
DEBUG_LEVEL = 10

def product(arr):
    if len(arr) < 3:
        raise Exception('must have at least 3 numbers')

    if len(arr) == 3:
        return arr[0]*arr[1]*arr[2]

    smallest_3_negative = []
    biggest_3_positive = []

    for ix in range(len(arr)):
        if len(smallest_3_negative) > 3:
            smallest_3_negative.remove(smallest_3_negative[3])

        if len(biggest_3_positive) > 3:
            biggest_3_positive.remove(biggest_3_positive[3])

        if arr[ix] < 0:
            if not smallest_3_negative:
                smallest_3_negative.appen(arr[ix])
                continue

            if arr[ix] < smallest_3_negative[0]:
                smallest_3_negative.insert(0, arr[ix])
                continue

            if arr[ix] < smallest_3_negative[1]:
                smallest_3_negative.insert(1, arr[ix])
                continue

            if arr[ix] < smallest_3_negative[2]:
                smallest_3_negative.insert(2, arr[ix])
                continue

        if not biggest_3_positive:
            biggest_3_positive.append(arr[ix])
            continue

        if arr[ix] > biggest_3_positive[0]:
            biggest_3_positive.insert(0, arr[ix])
            continue

        if arr[ix] > biggest_3_positive[1]:
            biggest_3_positive.insert(1, arr[ix])
            continue

        if arr[ix] > biggest_3_positive[2]:
            biggest_3_positive.insert(2, arr[ix])
            continue

    
    return out_arr

def test_driver(arr, expected_result):
    print('arr: {}, expected: {}'.format(arr, expected_result))

    actual_result = product(arr)
    if (actual_result == expected_result):
        print('PASS')
    else:
        print('FAIL: actual={}'.format(actual_result))

def test_sample():
    test_driver([1, 7, 3, 4], [84, 12, 28, 21])

def test_01():
    test_driver([1, 2, 3], [6, 3, 2])

test_sample()
