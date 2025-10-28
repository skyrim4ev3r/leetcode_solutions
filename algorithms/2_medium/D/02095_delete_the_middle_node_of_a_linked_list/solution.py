# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head
        prev = None
        fast = dummy
        slow = dummy

        while fast != None:
            fast = fast.next
            if fast != None:
                fast = fast.next

            prev = slow
            slow = slow.next

        prev.next = slow.next

        return dummy.next
