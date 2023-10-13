"""
2 - Add Two Numbers
https://leetcode.com/problems/add-two-numbers/description/
"""

DEBUG_LEVEL = 10

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

    def to_string(self):
        s = '{},'.format(self.val)
        node = self.next
        while node:
            s += '{},'.format(node.val)
            node = node.next

        return s

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        result = ListNode((l1.val + l2.val) % 10)
        over = int((l1.val + l2.val) / 10)
        if DEBUG_LEVEL>5: print('result={}, over={}'.format(result.val, over))

        l1 = l1.next
        l2 = l2.next
        result_digit = result
        while l1 and l2:
            result_digit.next = ListNode(0)
            result_digit = result_digit.next
            result_digit.val = (l1.val + l2.val + over) % 10
            over = int((l1.val + l2.val + over) / 10)
            if DEBUG_LEVEL>5: print('result={}, over={}'.format(result_digit.val, over))
            l1 = l1.next
            l2 = l2.next

        digit = l1
        if l2: digit = l2

        while digit:
            result_digit.next = ListNode(0)
            result_digit = result_digit.next
            result_digit.val = (digit.val + over) % 10
            over = int((digit.val +over) / 10)
            digit = digit.next

        if over:
            result_digit.next = ListNode(over)

        return result
        
def test_driver(l1, l2, expected_result):
    print(
        'l1: {}, l2: {}, expected: {}'.format(
            l1.to_string(), 
            l2.to_string(), 
            expected_result))

    sol = Solution()
    actual_result = sol.addTwoNumbers(l1, l2)
    if (actual_result.to_string() == expected_result):
        print('PASS')
    else:
        print('FAIL: actual={}'.format(actual_result.to_string()))

def test_sample():
    l1 = ListNode(2)
    l1_2 = ListNode(4)
    l1_3 = ListNode(3)
    l1.next = l1_2
    l1_2.next = l1_3

    l2 = ListNode(5)
    l2_2 = ListNode(6)
    l2_3 = ListNode(4)
    l2.next = l2_2
    l2_2.next = l2_3

    test_driver(l1, l2, '7,0,8,')

def test_01():
    l1 = ListNode(2)
    l1_2 = ListNode(4)
    l1_3 = ListNode(3)
    l1_4 = ListNode(6)
    l1.next = l1_2
    l1_2.next = l1_3
    l1_3.next = l1_4

    l2 = ListNode(5)
    l2_2 = ListNode(6)
    l2_3 = ListNode(4)
    l2.next = l2_2
    l2_2.next = l2_3

    test_driver(l1, l2, '7,0,8,6,')

def test_10():
    l1 = ListNode(9)
    l1_2 = ListNode(9)
    l1_3 = ListNode(9)
    l1_4 = ListNode(9)
    l1.next = l1_2
    l1_2.next = l1_3
    l1_3.next = l1_4

    l2 = ListNode(1)
    l2_2 = ListNode(1)
    l2.next = l2_2

    test_driver(l1, l2, '0,1,0,0,1,')

test_sample()
test_01()
test_10()