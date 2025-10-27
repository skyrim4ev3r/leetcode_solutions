# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr = head

        while curr.next != None:
            next_node = curr.next
            new_node = ListNode(gcd(curr.val, next_node.val))
            curr.next = new_node
            new_node.next = next_node
            curr = next_node

        return head
