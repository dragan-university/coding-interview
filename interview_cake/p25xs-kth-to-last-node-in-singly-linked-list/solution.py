class ListNode:
    def __init__(self, value):
        self.value = value
        self.next = None

def kth_to_last_node(position, root):
    node = root
    for i in range(position):
        node = node.next

    kth = root
    while node:
        kth = kth.next
        node = node.next

    return kth

a = ListNode("Angel Food")
b = ListNode("Bundt")
c = ListNode("Cheese")
d = ListNode("Devil's Food")
e = ListNode("Eccles")

a.next = b
b.next = c
c.next = d
d.next = e

node = kth_to_last_node(3, a)

if (node == c):
    print("PASS: "+node.value)
else:
    print("FAIL: expected: "+d.value+", actual: "+node.value)