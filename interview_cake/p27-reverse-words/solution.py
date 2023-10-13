"""
27 - https://www.interviewcake.com/question/python/reverse-words
"""
import traceback

DEBUG_LEVEL = 5

def reverse_message_part(message, begin, end):
    n = end - begin + 1
    for i in range(int(n/2)):
        t = message[begin+i]
        message[begin+i] = message[end-i]
        message[end-i] = t

def solution(message):
    """
    :type message: Array of char
    :rtype: Array of char
    """
    if DEBUG_LEVEL > 5: print('{}'.format(message))

    # reverse the whole array in place
    n = len(message)
    reverse_message_part(message, 0, n-1)
    if DEBUG_LEVEL > 7: print(message)

    # find all space chars
    spaces = [i for i, x in enumerate(message) if x == ' ']

    # reverse each word
    begin = 0
    for space in spaces:
        if DEBUG_LEVEL > 7: print('index: {}'.format(space))
        end = space - 1
        reverse_message_part(message, begin, end)
        if DEBUG_LEVEL > 7: print(message)
        begin = space + 1


    reverse_message_part(message, begin, n-1)

def test_driver(data, expected):
    test_name = traceback.extract_stack(None, 2)[0][2]
    print('=== {} ==='.format(test_name))
    print('data: {}, expected: {}'.format(data, expected))

    solution(data)
    if data == expected:
        print('PASS')
    else:
        print('FAIL: actual={}'.format(data))
    print()

def test_01():
    test_driver(
        ['c','a','k','e',' ','p','o','u','n','d', ' ','s','t','e','e','l'],
        ['s','t','e','e','l',' ','p','o','u','n','d',' ','c','a','k','e',])

test_01()
