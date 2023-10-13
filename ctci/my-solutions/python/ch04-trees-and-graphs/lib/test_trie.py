"""
test_trie
"""
import trie

def test_01():
    """
    test_01
    """
    my_trie = trie.Trie([
        'dragan',
        'dragance',
        'dragana'])

    print(my_trie.contains('drag'))
    print(my_trie.contains('drac'))



if __name__ == '__main__':
    test_01()
    