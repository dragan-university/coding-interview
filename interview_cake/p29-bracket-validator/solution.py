"""
Bracker Validator
"""

class BracketError(Exception):
    """
    Bracket erroro exception
    """

def pair_bracket(bracket):
    if (bracket == '('): return ')'
    if (bracket == '['): return ']'
    if (bracket == '{'): return '}'
    raise BracketError('Not a bracket!')

def bracket_validator(text):
    result = True
    stack = []
    for c in text:
        if c in '([{':
            stack.append(c)

        elif c in ')]}':
            if not stack:
                result = False
                break

            o = stack.pop()
            if pair_bracket(o) != c:
                result = False
            
        else:
            raise BracketError('Invalid character in text! ' + c);

    if stack:
        result = False

    return result

def test_driver(text, expected_result):
    print('*** ' + text + ' = ' + str(expected_result) + ' ***')
    actual_result = bracket_validator(text)

    if (expected_result == actual_result):
        print('PASS')
    else:
        print('FAIL')

    print 

test_driver('()', True)
test_driver('{', False)
test_driver('{[]()}', True)
test_driver('{[(])}', False)
