#!/bin/python3
"""
https://www.hackerrank.com/challenges/how-many-substrings

Analisys:
Create trie structure that will hold all possible substrings that can be built.
Then simply count the nodes in the trie structure, that would be solution.

Example:
'aab'

We create following trie

        root
       a    b
      a b

There are 4 nodes.
"""
DEBUG_LEVEL = 10

class TrieNode:
    """
    TrieNode
    """
    size = 0

    def __init__(self, character=None):
        self.character = character
        self.children = {}

    def add_word(self, word):
        """
        add_word
        """
        if not word:
            return

        first_char = word[0]

        child = self.get_child(first_char)
        if child is None:
            child = TrieNode(first_char)
            self.children[first_char] = child
            TrieNode.size += 1

        child.add_word(word[1:])

    def get_child(self, char):
        """
        Return child of this node that has 'char' as data
        Return None if no such child exists
        """
        return self.children.get(char)

class Trie:
    """
    Trie
    """
    def __init__(self, s):
        self.root = TrieNode()
        TrieNode.size = 0

        for i in range(len(s)):
            for j in range(i, len(s)):
                if DEBUG_LEVEL>5: print('add word: [{}:{}] = {}'.format(i, j, s[i:j+1]))
                self.root.add_word(s[i:j+1])

    def size(self):
        """
        size
        """
        return self.root.size

def how_many_substrings(s, left, right):
    """
    implements solution
    """
    ss = s[left:right+1]
    if DEBUG_LEVEL>5: print('substring is {}'.format(ss))
    t = Trie(ss)
    return t.size()

def test_how_many_substrings(s, left, right, expected_result):
    print('{}:{}-{} - expected {}'.format(s, left, right, expected_result))
    actual_result = how_many_substrings(s, left, right)
    if actual_result == expected_result:
        print(" PASS")
    else:
        print(" FAIL: E:", expected_result, " A:", actual_result)

    print('')

def test_hr_sample_1():
    test_how_many_substrings('aabaa', 1, 4, 8)

def test_hr_sample_2():
    test_how_many_substrings('aabaa', 0, 2, 5)

def hackerrank():
    n, q = input().strip().split(' ')
    n, q = [int(n), int(q)]
    s = input().strip()
    for a0 in range(q):
        left, right = input().strip().split(' ')
        left, right = [int(left), int(right)]
        print(how_many_substrings(s, left, right))

#hackerrank()
test_hr_sample_1()
test_hr_sample_2()
