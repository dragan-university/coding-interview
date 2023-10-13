"""
4 - merging meeting time
"""
DEBUG_LEVEL = 10

def merge_ranges(ranges):
    """
    ranges - [(a1, b1), (a2, b2), ..., (aN, bN)]

    returns condensed ranges:
        [(c1, d1), ..., (cK, dK)]
    """
    # sort ranges by first time (this takes O(n*lg(n)))
    ranges.sort(key=lambda x: x[0])

    # iterate through the sorted ranges and create condensed (this takes
    # O(n))
    last_condensed = [ranges[0][0], ranges[0][1]]
    condensed = [last_condensed]

    for ix in range(1, len(ranges)):
        if ranges[ix][0] <= last_condensed[1]:
            if last_condensed[1] <= ranges[ix][1]:
                last_condensed[1] = ranges[ix][1]
        else:
            last_condensed = [ranges[ix][0], ranges[ix][1]]
            condensed.append(last_condensed) 
    
    return [tuple(x) for x in condensed]

def test_driver(ranges, expected_result):
    print('ranges: {}, expected: {}'.format(ranges, expected_result))

    actual_result = merge_ranges(ranges)
    if (actual_result == expected_result):
        print('PASS')
    else:
        print('FAIL: actual={}'.format(actual_result))

def test_sample():
    ranges = [(0, 1), (3, 5), (4, 8), (10, 12), (9, 10)]
    expected_result = [(0, 1), (3, 8), (9, 12)]
    test_driver(ranges, expected_result)

test_sample()
