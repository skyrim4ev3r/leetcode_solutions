# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:

        count = 0
        curr = head

        while curr !=  None:
            count += 1
            curr = curr.next

        if count == 1:
            return True

        mid = count // 2
        curr = head

        for _ in range(1, mid):
            curr = curr.next

        next_node = curr.next
        curr.next = None
        if (count & 1) == 1:
            next_node = next_node.next

        prev = None

        while next_node != None:
            node = next_node
            next_node = node.next
            node.next = prev
            prev = node

        head1 = head
        head2 = prev

        # head1 and head2 have the same len, so checking one of them is enough.
        while head1 != None:
            if head1.val != head2.val:
                return False # If values don't match, then it is not a palindrome

            head1 = head1.next
            head2 = head2.next

        return True
