"""
11 - MillionGazillion

Solution is to use Trie data structure
"""
import traceback

DEBUG_LEVEL = 10

class TrieNode:
    """
    TrieNode
    """
    def __init__(self, character=None):
        self.character = character
        self.children = {}
        self._terminates = False

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

        if len(word) > 1:
            child.add_word(word[1:])
        else:
            child.mark_complete_word()

    def get_child(self, char):
        """
        Return child of this node that has 'char' as data
        Return None if no such child exists
        """
        return self.children.get(char)

    def is_complete_word(self):
        """
        Returns whether this node represents the end of a complete word
        """
        return self._terminates

    def mark_complete_word(self):
        """
        Marks that this node represents the end of a complete word
        """
        self._terminates = True


class Trie:
    """
    Trie
    """
    def __init__(self, words):
        self.root = TrieNode()

        for word in words:
            self.root.add_word(word)

    def contains(self, word, match_type='prefix'):
        """
        Checks whether this trie contains the given word.
        
        If match_type is 'prefix' only checks if word is prefix of another word
        otherwise checks if word is a complete word in the trie
        """
        last_node = self.root
        for char in word:
            last_node = last_node.get_child(char)
            if last_node is None:
                return False

        if match_type == 'prefix':
            return True
        else:
            return last_node.is_complete_word()

def solution(pages, page):
    """
    :type pages: list of str
    :type page: str
    :rtype: bool
    """
    _trie = Trie(pages)
    return _trie.contains(page, 'complete')

def test_driver(pages, page, expected):
    test_name = traceback.extract_stack(None, 2)[0][2]
    print('=== {} ==='.format(test_name))
    print('pages: {}, page: {}, expected: {}'.format(pages, page, expected))

    actual = solution(pages, page)
    if actual == expected:
        print('PASS')
    else:
        print('FAIL: actual={}'.format(actual))
    print()

def test_01():
    pages = [
        'www.b92.net',
        'www.cnn.com',
        'www.cnndaily.com',
    ]

    test_driver(pages, 'www.b92.net', True)

def test_02():
    pages = [
        'www.b92.net',
        'www.cnn.com',
        'www.cnndaily.com',
    ]

    test_driver(pages, 'www.b92x.net', False)

test_01()
test_02()
