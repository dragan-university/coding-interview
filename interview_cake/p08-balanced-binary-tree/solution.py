"""
8 - Balanced Binary Tree
"""
import math

DEBUG_LEVEL = 10

class BinaryTreeNode:
    min_depth = math.inf
    max_depth = 0

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

def is_btree_balanced(root):
    BinaryTreeNode.min_depth = math.inf
    BinaryTreeNode.max_depth = 0
    curr_depth = 0

    return is_btree_balanced_r(root, curr_depth)

def is_btree_balanced_r(node, curr_depth):
    if DEBUG_LEVEL>5: print('check node: {}'.format(node.value))
    if node.left == None and node.right == None:
        BinaryTreeNode.max_depth = max(BinaryTreeNode.max_depth, curr_depth)
        BinaryTreeNode.min_depth = min(BinaryTreeNode.min_depth, curr_depth)

        if DEBUG_LEVEL>5: print('leaf - min:{}, max:{}'.format(BinaryTreeNode.min_depth, BinaryTreeNode.max_depth))

        if BinaryTreeNode.max_depth - BinaryTreeNode.min_depth > 1:
            return False

        return True

    if node.left:
        result = is_btree_balanced_r(node.left, curr_depth+1)

    if result and node.right:
        result = is_btree_balanced_r(node.right, curr_depth+1)
        
    return result


def test_driver(btree_as_string, root, expected_result):
    print('btree: {}, expected: {}'.format(btree_as_string, expected_result))

    actual_result = is_btree_balanced(root)
    if (actual_result == expected_result):
        print('PASS')
    else:
        print('FAIL: actual={}'.format(actual_result))

def test_01():
    root = BinaryTreeNode('r')
    na = BinaryTreeNode('a')
    nb = BinaryTreeNode('b')
    nc = BinaryTreeNode('c')
    root.left = na
    root.right = nb
    na.left = nc

    test_driver('r-a-b-c', root, True)

def test_02():
    root = BinaryTreeNode('r')
    na = BinaryTreeNode('a')
    nb = BinaryTreeNode('b')
    nc = BinaryTreeNode('c')
    nd = BinaryTreeNode('d')
    root.left = na
    root.right = nb
    na.left = nc
    nc.left = nd

    test_driver('r-a-b-c-*-*-*-d', root, False)

test_01()
test_02()
