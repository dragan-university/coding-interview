"""
Largest Element
"""

DEBUG = True

class Stack:
    # initialize an empty list
    def __init__(self):
        self.items = []

    # push a new item to the last index
    def push(self, item):
        self.items.append(item)

    # remove the last item
    def pop(self):
        # if the stack is empty, return None
        # (it would also be reasonable to throw an exception)
        if not self.items:
            return None
        return self.items.pop()

    # see what the last item is
    def peek(self):
        if not self.items:
            return None
        return self.items[-1]

    def print(self):
        for item in self.items:
            print('{}:'.format(item), end='')
        print()


class MaxStack:
    def __init__(self):
        self.stack = Stack()
        self.max_values = Stack()

    def push(self, item):
        self.stack.push(item)

        # if max_stack is empty or this is new max value push the value
        # to the max_stack
        if not self.max_values.peek() or item >= self.max_values.peek():
            self.max_values.push(item)

        if DEBUG: self.print()

    def pop(self):
        if not self.stack.peek():
            return None

        # if this is current max value, pop it from the max_stack
        if self.stack.peek() == self.max_values.peek():
            self.max_values.pop()

        value = self.stack.pop()
        if DEBUG: self.print()

        return value

    def peek(self):
        return self.stack.peek()

    def get_max(self):
        return self.max_values.peek()

    def print(self):
        self.stack.print()
        print('max={}'.format(self.get_max()))

def test_05():
    ms = MaxStack()
    ms.push(1)
    assert(ms.get_max() == 1)
    ms.push(7)
    assert(ms.get_max() == 7)
    ms.push(3)
    assert(ms.get_max() == 7)
    ms.push(5)
    assert(ms.get_max() == 7)
    ms.push(11)
    assert(ms.get_max() == 11)
    ms.push(4)
    assert(ms.get_max() == 11)
    ms.push(6)
    assert(ms.get_max() == 11)

    ms.pop()
    ms.pop()
    ms.pop()
    assert(ms.get_max() == 7)

test_05()