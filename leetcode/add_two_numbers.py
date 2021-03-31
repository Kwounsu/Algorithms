def to_string(self, node: ListNode) -> List:
    string = ''

    while node:
        string += str(node.val)
        node = node.next

    return string


def to_linked_list(self, number: str) -> ListNode:
    node = ListNode()
    linked_list = node

    for n in number:
        node.next = ListNode(int(n))
        node = node.next

    return linked_list.next


def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
    num1, num2 = self.to_string(l1), self.to_string(l2)

    result = str(int(num1[::-1])+int(num2[::-1]))[::-1]

    return self.to_linked_list(result)
