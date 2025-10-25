# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head

        right = head

        for i in range(n):
            right = right.next

        left = head
        prev = dummy

        while right != None:
            right = right.next
            prev = left
            left = left.next

        prev.next = left.next

        return dummy.next
