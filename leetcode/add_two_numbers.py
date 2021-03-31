# def to_string(self, node: ListNode) -> List:
#     string = ''

#     while node:
#         string += str(node.val)
#         node = node.next

#     return string


# def to_linked_list(self, number: str) -> ListNode:
#     node = ListNode()
#     linked_list = node

#     for n in number:
#         node.next = ListNode(int(n))
#         node = node.next

#     return linked_list.next


def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
#     num1, num2 = self.to_string(l1), self.to_string(l2)

#     result = str(int(num1[::-1])+int(num2[::-1]))[::-1]

#     return self.to_linked_list(result)


    # 전가산기(Full adder): 아래 자리수에서 발생한 캐리까지 포함한 세 비트를 더하는 논리회로
    root = head = ListNode(0)

    carry = 0
    while l1 or l2 or carry:
        val_sum = 0
        if l1:
            val_sum += l1.val
            l1 = l1.next
        if l2:
            val_sum += l2.val
            l2 = l2.next

        carry, val = divmod(val_sum + carry, 10)
        head.next = ListNode(val)
        head = head.next

    return root.next

