"""
NOT COMPLETED
https://www.interviewcake.com/question/python/graph-coloring

Example:

a -- b -- c
|      \  |
|       \ |
e ------- d

a - b, e
b - a, c, d
c - b, d
d - b, c, e
e - a, d

method 1
========
colored = none; blank = all

a ---
  neighbors colors = none
  a.color = 1
  colored = a
  blank = b,c,d,e

b ---
  neighbour colors = 1
  b.color = 2
  colored = a,b
  blank = c,d,e

c ---
  neighbour colors = 2
  b.color = 1
  colored = a,b,c
  blank = d,e

d ---
  neighbour colors = 1,2
  b.color = 3
  colored = a,b,c,d
  blank = e

e ---
  neighbour colors = 1,3
  b.color = 2
  colored = a,b,c,d,e
  blank = none

method 2
========
a - a1, b2, e3; q = b, e; colored = a, b, e; blank = c, d
b - b2
  connected to blank c which is not connected to any other colored so c1
  connected to d which is connected also to colored e3 and c1 so d4
  q = e, c, d; blank = none
  because blank = none we are done
"""
import traceback

DEBUG_LEVEL = 5

def find_min_color_not_in_neighbours(node):
    test_name = traceback.extract_stack(None, 2)[0][2]
    print('=== {} ==='.format(test_name))
    print("node={}".format(node.label))
    colors = set()
    for n in node.neighbors:
        print("-neigbhour={}".format(n.label))
        if n.color:
            colors.add(n.color)
        
    if not colors:
        return 1
    else:
        return min(colors)

def max_color(graph):
    test_name = traceback.extract_stack(None, 2)[0][2]
    print('=== {} ==='.format(test_name))
    colors = set()
    for n in graph:
        if n.color:
            colors.add(n.color)
        
    return max(colors)

def solution(graph):
    test_name = traceback.extract_stack(None, 2)[0][2]
    print('=== {} ==='.format(test_name))
    for node in graph:
        color = find_min_color_not_in_neighbours(node)
        print("- color={}".format(color))
        node.color = color
    return max_color(graph)

def test_driver(graph, expected_result):
    test_name = traceback.extract_stack(None, 2)[0][2]
    print('=== {} ==='.format(test_name))
    actual_result = solution(graph)

    if (expected_result == actual_result):
        print('PASS')
    else:
        print('FAIL') 

class GraphNode:
    def __init__(self, label):
        self.label = label
        self.neighbors = set()
        self.color = None

def test_001():
    test_name = traceback.extract_stack(None, 2)[0][2]
    print('=== {} ==='.format(test_name))
    a = GraphNode('a')
    b = GraphNode('b')
    c = GraphNode('c')

    a.neighbors.add(b)
    b.neighbors.add(a)
    b.neighbors.add(c)
    c.neighbors.add(b)

    graph = [a, b, c]

    test_driver(graph, 2)

test_001()
