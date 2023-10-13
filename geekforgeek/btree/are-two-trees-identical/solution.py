#!/usr/local/bin/python
#  -*- coding: utf-8 -*-
"""
https://www.geeksforgeeks.org/write-c-code-to-determine-if-two-trees-are-identical/

"""
DEBUG = False
RUN_ALL = True

# A binary tree node has data, pointer to left child 
# and a pointer to right child 
class Node: 
    # Constructor to create a new node 
    def __init__(self, data): 
        self.data = data 
        self.left = None
        self.right = None

def tree_from_list(l):
    """
    Converts a binary tree defined as list into a tree defined as Node objects

    Arguments:
    l: tree defined as list (e.g. [1,2,3,None,4,None,5,6,7])

    return: root node of the tree
    """
    if l is None:
        return None

    nodes = [Node(l[0])]
    for ix in range(1, len(l), 2):
        lnode = None
        rnode = None

        if l[ix]:
            lnode = Node(l[ix])
            nodes.append(lnode)

        if l[ix+1]:
            rnode = Node(l[ix+1])
            nodes.append(rnode)

        parent_node_idx = int(ix/2)
        nodes[parent_node_idx].left = lnode
        nodes[parent_node_idx].right = rnode

    return nodes[0]            

def areTreesIdentical(t1, t2):
    """
    t1 - Node
    t2 - Node

    return: True/False
    """
    if t1 is None and t2 is None:
        return True

    if t1 is None or t2 is None:
        return False

    c1 = t1.data == t2.data
    c2 = areTreesIdentical(t1.left, t2.left)
    c3 = areTreesIdentical(t1.right, t2.right)

    return c1 and c2 and c3

def test_driver(t1, t2, expected_result):
    print('t1 = {}, t2 = {}'.format(t1, t2))
    actual_result = areTreesIdentical(tree_from_list(t1), tree_from_list(t2))
    print('actual_result = {}'.format(actual_result))
    if actual_result == expected_result:
        print('PASS')
    else:
        print('FAIL: E={}, A={}'.format(expected_result, actual_result))
    
def test_1():
    test_driver([1,2,3], [1,2,3], True)

def test_2():
    test_driver([1,2,3], [1,3,2], False)

def test_3():
    test_driver([1,2,3,None,4,None,5], [1,2,3,None,4,None,5], True)

def test_4():
    test_driver([1,2,3,4,None,None,5], [1,2,3,None,4,None,5], False)

if RUN_ALL: test_1()
if RUN_ALL: test_2()
if RUN_ALL: test_3()
if RUN_ALL: test_4()
