"""
trie.py
"""

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

    def contains(self, prefix):
        """
        Checks whether this trie contains a string with the prefix passed in
        as argument
        """
        last_node = self.root
        for char in prefix:
            last_node = last_node.get_child(char)
            if last_node is None:
                return False

        return True
