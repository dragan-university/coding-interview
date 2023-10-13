"""
10 - https://www.interviewcake.com/question/java/second-largest-item-in-bst
"""
import traceback

DEBUG_LEVEL = 0

class BinaryTreeNode:

    def __init__(self, value):
        self.value = value
        self.left  = None
        self.right = None

    def insert_left(self, value):
        self.left = BinaryTreeNode(value)
        return self.left

    def insert_right(self, value):
        self.right = BinaryTreeNode(value)
        return self.right

def find_max(node):
    parent = None
    while node:
        if not node.right:
            return node, parent

        parent = node
        node = node.right

def solution(root):
    """
    type: root BinaryTreeNode
    rtype: int
    """
    if not root.left and not root.right:
        raise Exception('you must provide at least 2 elements')

    max_node, parent_node = find_max(root)

    if max_node.left:
        second_max, _ = find_max(max_node.left)
        return second_max.value
    else:
        return parent_node.value

def test_driver(tree_as_string, root, expected):
    test_name = traceback.extract_stack(None, 2)[0][2]
    print('=== {} ==='.format(test_name))
    print('tree: {} -- expected: {}'.format(tree_as_string, expected))

    actual = None
    try:
        actual = solution(root)
    except Exception as e:
        if str(e) == expected:
            print('PASS: exception')
        else:
            print('FAIL: unexpected exception: {}'.format(str(e)))
        print('')
        return

    if (actual == expected):
        print('PASS')
    else:
        print('FAIL: actual={}'.format(actual))
    print('')

def test_123():
    root = BinaryTreeNode(2)
    n1 = BinaryTreeNode(1)
    n3 = BinaryTreeNode(3)
    root.left = n1
    root.right = n3

    test_driver('(2, (1, 3))', root, 2)

def test_12():
    root = BinaryTreeNode(2)
    n1 = BinaryTreeNode(1)
    root.left = n1

    test_driver('(2, (1, *))', root, 1)

def test_23():
    root = BinaryTreeNode(2)
    n3 = BinaryTreeNode(3)
    root.right = n3

    test_driver('(2, (*, 3))', root, 2)

def test_2():
    root = BinaryTreeNode(2)

    test_driver('(2, (*, *))', root, 'you must provide at least 2 elements')

def test_2_7_11_8_10():
    root = BinaryTreeNode(2)
    n7 = BinaryTreeNode(7)
    n8 = BinaryTreeNode(8)
    n10 = BinaryTreeNode(10)
    n11 = BinaryTreeNode(11)
    root.right = n7
    n7.right = n11
    n11.left = n8
    n8.right = n10

    test_driver('(2, (*, 7, (*, 11, (8, (*, 10), *))))', root, 10)

test_123()
test_12()
test_23()
test_2()
test_2_7_11_8_10()
