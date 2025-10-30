# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head

        prev = dummy
        curr_node = prev.next

        while curr_node != None:
            next_node = curr_node.next

            if next_node == None:
                break

            prev.next = next_node
            curr_node.next = next_node.next
            next_node.next = curr_node
            prev = curr_node
            curr_node = curr_node.next

        new_head = dummy.next
        dummy.next = None
        return new_head
