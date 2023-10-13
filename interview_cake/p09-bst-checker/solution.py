"""
9 - Binary Search Tree Checker
"""
import math

DEBUG_LEVEL = 0

class BinaryTreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

    def insert_left(self, value):
        self.left = BinaryTreeNode(value)
        return self.left

    def insert_right(self, value):
        self.right = BinaryTreeNode(value)
        return self.right

def is_bst(node):
    """
    return true if tree under node is bst
    ---
    Check if an in-order traversal of the tree is sorted
    Speed complexity: O(n) because each node is visited once
    Space complexity: O(lgn) for balanced tree because it is recursive call
    """
    return is_bst_r(node, -math.inf)

def is_bst_r(node, previous_node_value):
    if node is None:
        return True
    if DEBUG_LEVEL>5: print('ENTER: node: {}, prev_node: {}'.format(node.value, previous_node_value))

    if not is_bst_r(node.left, previous_node_value):
        return False

    if node.left:
        previous_node_value = node.left.value
    if DEBUG_LEVEL>7: print('LEFT: node: {}, prev_node: {}'.format(node.value, previous_node_value))
    if node.value < previous_node_value:
        return False

    if not is_bst_r(node.right, node.value):
        return False

    return True

# interview cake solution (iterative)
def is_bst_ic(root):
    # start at the root, with an arbitrarily low lower bound
    # and an arbitrarily high upper bound
    node_and_bounds_stack = [(root, -float('inf'), float('inf'))]

    # depth-first traversal
    while len(node_and_bounds_stack):
        node, lower_bound, upper_bound = node_and_bounds_stack.pop()

        # if this node is invalid, we return false right away
        if (node.value <= lower_bound) or (node.value >= upper_bound):
            return False

        if node.left:
            # this node must be less than the current node
            node_and_bounds_stack.append((node.left, lower_bound, node.value))
        if node.right:
            # this node must be greater than the current node
            node_and_bounds_stack.append((node.right, node.value, upper_bound))

    # if none of the nodes were invalid, return true
    # (at this point we have checked all nodes)
    return True

def test_driver(btree_as_string, root, expected_result):
    print('btree: {}, expected: {}'.format(btree_as_string, expected_result))

    actual_result = is_bst_ic(root)
    if (actual_result == expected_result):
        print('PASS')
    else:
        print('FAIL: actual={}'.format(actual_result))

def test_y_01():
    root = BinaryTreeNode(50)
    n30 = BinaryTreeNode(30)
    n80 = BinaryTreeNode(80)
    n20 = BinaryTreeNode(20)
    n40 = BinaryTreeNode(40)
    root.left = n30
    root.right = n80
    n30.left = n20
    n30.right = n40

    test_driver('50-30-80-20-40', root, True)

def test_y_02():
    root = BinaryTreeNode(50)
    n80 = BinaryTreeNode(80)
    root.right = n80

    test_driver('50---80', root, True)

def test_y_03():
    root = BinaryTreeNode(50)
    n10 = BinaryTreeNode(10)
    n90 = BinaryTreeNode(90)
    n70 = BinaryTreeNode(70)
    n60 = BinaryTreeNode(60)
    n80 = BinaryTreeNode(80)
    
    root.left = n10
    root.right = n90

    n90.left = n70
    
    n70.left = n60
    n70.right = n80

    test_driver('50-10-90-*-*-70-*-60-80', root, True)

def test_n_01():
    root = BinaryTreeNode(50)
    n30 = BinaryTreeNode(30)
    n80 = BinaryTreeNode(80)
    n20 = BinaryTreeNode(20)
    n40 = BinaryTreeNode(40)
    root.left = n30
    root.right = n80
    n30.left = n40
    n30.right = n20

    test_driver('50-30-80-20-40', root, False)

def test_n_02():
    root = BinaryTreeNode(50)
    n80 = BinaryTreeNode(80)
    root.left = n80

    test_driver('50-80', root, False)

test_y_01()
test_y_02()
test_y_03()
test_n_01()
test_n_02()
