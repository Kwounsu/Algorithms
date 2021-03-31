class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def reverse_linked_list(node: ListNode) -> ListNode:
    rev = None

    while node:
        rev, rev.next, node = node, rev, node.next

    return rev


def to_list(node: ListNode) -> List:
    new_list = []

    while node:
        new_list.append(node.val)
        node = node.next

    return new_list


def to_linked_list(number: str) -> ListNode:
    node = ListNode()
    linked_list = node

    for n in number:
        node.next = ListNode(int(n))
        node = node.next

    return linked_list.next


def to_reversed_linked_list(number: str) -> ListNode:
    node = ListNode()
    rev = None

    for n in number:
        node = ListNode(int(n))
        node.next = rev
        rev = node

    return node
