"""
16 - https://www.interviewcake.com/question/python/cake-thief
"""
import traceback
import bisect

DEBUG_LEVEL = 10

def max_duffel_bag_value(cake_tuples, capacity):
    """
    :list cake_tuples: 
    :int capacity:
    :rtype: int
    """
    if DEBUG_LEVEL > 5: print('{} - {}'.format(cake_tuples, capacity))

    # create list with specific weigth sorted by specific weigth
    specific_cake_tuples = []
    for cake_tuple in cake_tuples:
        specific_cake_tuple = (float(cake_tuple[1])/cake_tuple[0], cake_tuple[0], cake_tuple[1])
        bisect.insort(specific_cake_tuples, specific_cake_tuple)
    print(specific_cake_tuples)

    current_capacity = capacity
    tuple_index = len(cake_tuples)-1
    bag_value = 0

    while (current_capacity > 0 and tuple_index >= 0):
        if (specific_cake_tuples[tuple_index][1] <= current_capacity):
            cake_count = current_capacity/specific_cake_tuples[tuple_index][1]
            current_capacity -= cake_count*specific_cake_tuples[tuple_index][1]
            bag_value += cake_count*specific_cake_tuples[tuple_index][2]
        tuple_index -= 1

    return bag_value

def test_driver(cake_tuples, capacity, expected):
    test_name = traceback.extract_stack(None, 2)[0][2]
    print('=== {} ==='.format(test_name))
    print('cake_tuples: {}, capacity: {}, expected: {}'.format(cake_tuples, capacity, expected))

    actual = max_duffel_bag_value(cake_tuples, capacity)
    if actual == expected:
        print('PASS')
    else:
        print('FAIL: actual={}'.format(actual))
    print()

def test_01():
    test_driver([(7,160), (3,90), (2,15)], 20, 555)

def test_02():
    test_driver([(7,220), (5,150), (2,15)], 20, 740)

test_01()
test_02()
