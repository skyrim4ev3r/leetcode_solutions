# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        hashset = set(nums)

        dummy = ListNode(0)
        dummy.next = head

        prev = dummy
        curr = dummy.next

        while curr != None:
            if curr.val not in hashset:
                prev = curr
                curr = curr.next
            else:
                prev.next = curr.next
                curr = curr.next

        return dummy.next
