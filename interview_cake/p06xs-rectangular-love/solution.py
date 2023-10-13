"""
6 - rectangular love

https://www.interviewcake.com/question/python/rectangular-love
"""
import sys
import traceback

DEBUG_LEVEL = 17

no_overlap = {'left_x': 0, 'bottom_y': 0, 'width': 0, 'height': 0}

def is_order(x1, x2, x3, x4):
    return x1<=x2 and x2<=x3 and x3<=x4

def solution(r1, r2):
    """
    r1, r2 are rectangles {'left_x': x, 'bottom_y': y, 'width': w, 'height': h}

    returns rectangle
    """
    if r2['left_x'] < r1['left_x']:
        if DEBUG_LEVEL>7: print('switch')
        r1, r2 = r2, r1

    # is r1.rx < r2.lx
    if r1['left_x']+r1['width'] <= r2['left_x']:
        if DEBUG_LEVEL>7: print('r2 is on the right side of r1')
        return no_overlap

    # is r1.ty < r2.by or r2.ty < r1.by
    if r1['bottom_y']+r1['height'] <= r2['bottom_y'] or r2['bottom_y']+r2['height'] <= r1['bottom_y']:
        if DEBUG_LEVEL>7: print('r2 is above r1 or vice versa')
        return no_overlap

    # is order r1.lx, r2.lx, r1.rx, r2.rx
    if is_order(r1['left_x'], r2['left_x'], r1['left_x']+r1['width'], r2['left_x']+r2['width']):

        # is order r1.by, r2.by, r1.ty, r2.ty
        if is_order(r1['bottom_y'], r2['bottom_y'], r1['bottom_y']+r1['height'], r2['bottom_y']+r2['height']):
            # corners overlap with r1 down
            if DEBUG_LEVEL>7: print('corners overlap with r1 down')
            return {
                'left_x': r2['left_x'], 
                'bottom_y': r2['bottom_y'], 
                'width': r1['left_x']+r1['width']-r2['left_x'], 
                'height': r1['bottom_y']+r1['height']-r2['bottom_y']
                }
            
        # is order r1.by, r2.by, r2.ty, r1.ty
        if is_order(r1['bottom_y'], r2['bottom_y'], r2['bottom_y']+r2['height'], r1['bottom_y']+r1['height']):
            # r2 is inside r1 from the r1's right side
            if DEBUG_LEVEL>7: print('r2 is inside r1 from the r1\'s right side')
            return {
                'left_x': r2['left_x'], 
                'bottom_y': r2['bottom_y'], 
                'width': r1['left_x']+r1['width']-r2['left_x'], 
                'height': r2['height']
                }

        # is order r2.by, r1.by, r2.ty, r1.ty
        if is_order(r2['bottom_y'], r1['bottom_y'], r2['bottom_y']+r2['height'], r1['bottom_y']+r1['height']):
            # corners overlap with r1 up
            if DEBUG_LEVEL>7: print('corners overlap with r1 up')
            return {
                'left_x': r2['left_x'], 
                'bottom_y': r1['bottom_y'], 
                'width': r1['left_x']+r1['width']-r2['left_x'], 
                'height': r2['bottom_y']+r2['height']-r1['bottom_y']
                }

        # is order r2.by, r1.by, r1.ty, r2.ty
        if is_order(r2['bottom_y'], r1['bottom_y'], r1['bottom_y']+r1['height'], r2['bottom_y']+r2['height']):
            # r2 is inside r1 from the r1's left side
            if DEBUG_LEVEL>7: print('r2 is inside r1 from the r1\'s left side')
            return {
                'left_x': r2['left_x'], 
                'bottom_y': r1['bottom_y'], 
                'width': r1['left_x']+r1['width']-r2['left_x'], 
                'height': r1['height']
                }

    # is order r1.lx, r2.lx, r2.rx, r1.rx
    if is_order(r1['left_x'], r2['left_x'], r2['left_x']+r2['width'], r1['left_x']+r1['width']):

        # is order r1.by, r2.by, r1.ty, r2.ty
        if is_order(r1['bottom_y'], r2['bottom_y'], r1['bottom_y']+r1['height'], r2['bottom_y']+r2['height']):
            # r2 is inside r1 from the r1's top side
            if DEBUG_LEVEL>7: print('r2 is inside r1 from the r1\'s top side')
            return {
                'left_x': r2['left_x'], 
                'bottom_y': r2['bottom_y'], 
                'width': r2['width'], 
                'height': r1['bottom_y']+r1['height']-r2['bottom_y']
                }
            
        # is order r1.by, r2.by, r2.ty, r1.ty
        if is_order(r1['bottom_y'], r2['bottom_y'], r2['bottom_y']+r2['height'], r1['bottom_y']+r1['height']):
            # r2 is inside r1 completely
            if DEBUG_LEVEL>7: print('r2 is inside r1 completely')
            return {
                'left_x': r2['left_x'], 
                'bottom_y': r2['bottom_y'], 
                'width': r2['width'], 
                'height': r2['height']
                }

        # is order r2.by, r1.by, r2.ty, r1.ty
        if is_order(r2['bottom_y'], r1['bottom_y'], r2['bottom_y']+r2['height'], r1['bottom_y']+r1['height']):
            # r2 is inside r1 from the r1's bottom side
            if DEBUG_LEVEL>7: print('r2 is inside r1 from the r1\'s bottom side')
            return {
                'left_x': r2['left_x'], 
                'bottom_y': r1['bottom_y'], 
                'width': r2['width'], 
                'height': r2['bottom_y']+r2['height']-r1['bottom_y']
                }

        # is order r2.by, r1.by, r1.ty, r2.ty
        if is_order(r2['bottom_y'], r1['bottom_y'], r1['bottom_y']+r1['height'], r2['bottom_y']+r2['height']):
            # r1 and r2 form cross
            if DEBUG_LEVEL>7: print('r1 and r2 form cross')
            return {
                'left_x': r2['left_x'],
                'bottom_y': r1['bottom_y'],
                'width': r2['width'],
                'height': r1['height']
                }

    if DEBUG_LEVEL>5: print('{} - {}'.format(r1, r2))
    return no_overlap

def test_driver(r1, r2, expected_result):
    test_name = traceback.extract_stack(None, 2)[0][2]
    print('=== {} ==='.format(test_name))
    print('r1:       {}\nr2:       {}\nexpected: {}'.format(r1, r2, expected_result))

    actual_result = solution(r1, r2)
    if (actual_result == expected_result):
        print('PASS')
    else:
        print('FAIL: actual={}'.format(actual_result))
    print()

def test_corner_overlap_r1_down():
    r1 = {'left_x': 0, 'bottom_y': 0, 'width': 10, 'height': 10}
    r2 = {'left_x': 2, 'bottom_y': 2, 'width': 10, 'height': 10}
    expected = {'left_x': 2, 'bottom_y': 2, 'width': 8, 'height': 8}
    test_driver(r1, r2, expected)

def test_corner_overlap_r1_up():
    r1 = {'left_x': 0, 'bottom_y': 0, 'width': 10, 'height': 10}
    r2 = {'left_x': 2, 'bottom_y': -2, 'width': 10, 'height': 10}
    expected = {'left_x': 2, 'bottom_y': 0, 'width': 8, 'height': 8}
    test_driver(r1, r2, expected)

def test_cross():
    r1 = {'left_x': 0, 'bottom_y': 0, 'width': 10, 'height': 10}
    r2 = {'left_x': 2, 'bottom_y': -2, 'width': 6, 'height': 14}
    expected = {'left_x': 2, 'bottom_y': 0, 'width': 6, 'height': 10}
    test_driver(r1, r2, expected)

def test_r2_into_r1_from_bottom():
    r1 = {'left_x': 0, 'bottom_y': 0, 'width': 10, 'height': 10}
    r2 = {'left_x': 2, 'bottom_y': -2, 'width': 6, 'height': 6}
    expected = {'left_x': 2, 'bottom_y': 0, 'width': 6, 'height': 4}
    test_driver(r1, r2, expected)

def test_r2_into_r1_from_right():
    r1 = {'left_x': 0, 'bottom_y': 0, 'width': 10, 'height': 10}
    r2 = {'left_x': 2, 'bottom_y': 2, 'width': 10, 'height': 6}
    expected = {'left_x': 2, 'bottom_y': 2, 'width': 8, 'height': 6}
    test_driver(r1, r2, expected)

def test_r2_into_r1_from_left():
    r1 = {'left_x': 0, 'bottom_y': 0, 'width': 10, 'height': 10}
    r2 = {'left_x': -2, 'bottom_y': 2, 'width': 10, 'height': 6}
    expected = {'left_x': 0, 'bottom_y': 2, 'width': 8, 'height': 6}
    test_driver(r1, r2, expected)

def test_r1_in_r2_completely():
    r1 = {'left_x': 0, 'bottom_y': 0, 'width': 10, 'height': 10}
    r2 = {'left_x': -2, 'bottom_y': -2, 'width': 14, 'height': 14}
    expected = {'left_x': 0, 'bottom_y': 0, 'width': 10, 'height': 10}
    test_driver(r1, r2, expected)

def test_no_overlap_r1left_equal_r2right():
    r1 = {'left_x': 0, 'bottom_y': 0, 'width': 10, 'height': 10}
    r2 = {'left_x': -2, 'bottom_y': 0, 'width': 2, 'height': 14}
    expected = no_overlap
    test_driver(r1, r2, expected)

test_no_overlap_r1left_equal_r2right()
test_corner_overlap_r1_down()
test_corner_overlap_r1_up()
test_cross()
test_r2_into_r1_from_bottom()
test_r2_into_r1_from_right()
test_r2_into_r1_from_left()
test_r1_in_r2_completely()