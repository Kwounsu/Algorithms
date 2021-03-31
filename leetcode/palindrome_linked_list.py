def isPalindrome(self, head: ListNode) -> bool:
    if not head:
        return True

    slow = fast = head
    rev = None
    
    # create reversed linked list with runners
    while fast and fast.next:
        fast = fast.next.next
        rev, rev.next, slow = slow, rev, slow.next
    # if odd: exclude midium value
    if fast:
        slow = slow.next

    # check front half and last half from middle to the edges
    while slow:
        if rev.val != slow.val:
            return False
        slow, rev = slow.next, rev.next

    return True
