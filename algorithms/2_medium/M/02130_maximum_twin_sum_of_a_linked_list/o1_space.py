INT_MIN = -sys.maxsize - 1
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def pairSum(self, head: Optional[ListNode]) -> int:

        count = 0
        curr = head

        while curr != None:
            count += 1
            curr = curr.next

        curr = head
        half = count // 2

        for i in range(1, half):
            curr = curr.next

        temp = curr.next
        curr.next = None
        curr = temp
        prev = None

        while curr != None:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node

        head1 = head
        head2 = prev
        max_sum = INT_MIN

        # len of head1 and head2 are equal, so checking only one of them is enough
        while head1 != None:
            max_sum = max(max_sum, head1.val + head2.val)
            head1 = head1.next
            head2 = head2.next

        return max_sum
