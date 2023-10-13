"""
test_trie
"""
import traceback
import trie

def test_driver(words, word, match_type, expected):
    test_name = traceback.extract_stack(None, 2)[0][2]
    print('=== {} ==='.format(test_name))
    print('{} - {} - {} - {}'.format(words, word, match_type, expected))

    _trie = trie.Trie(words)
    actual = _trie.contains(word, match_type)

    if actual == expected:
        print('PASS')
    else:
        print('FAIL: actual={}'.format(actual))
    print()

def test_01():
    words = [
        'dragan',
        'dragance',
        'dragana']

    test_driver(words, 'drag', 'prefix', True)

def test_01_1():
    words = [
        'dragan',
        'dragance',
        'dragana']

    test_driver(words, 'drag', 'full', False)

def test_02():
    words = [
        'dragan',
        'dragance',
        'dragana']

    test_driver(words, 'drac', 'prefix', False)

def test_03():
    words = [
        'dragan',
        'dragance',
        'dragana']

    test_driver(words, 'dragan', 'full', True)

test_01()
test_01_1()
test_02()
test_03()