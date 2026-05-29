# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        tail_part_one = dummy

        for _ in range(1, left):
            tail_part_one = tail_part_one.next

        curr = tail_part_one.next
        head_part_two = None
        tail_part_two = curr

        for _ in range(left, right + 1):
            next_node = curr.next
            curr.next = head_part_two
            head_part_two = curr
            curr = next_node

        tail_part_one.next = head_part_two
        tail_part_two.next = curr

        return dummy.next
