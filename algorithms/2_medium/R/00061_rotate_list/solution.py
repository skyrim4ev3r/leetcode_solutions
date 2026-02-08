# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def calc_len_and_shift_count(self, head: Optional[ListNode], k: int) -> (int, int):
        n = 0
        curr = head

        while curr != None:
            n += 1
            curr = curr.next

        shift_count = 0 if n == 0 else (n - k % n) % n

        return (n, shift_count)

    def split_into_two_list(
        self,
        head: Optional[ListNode],
        shift_count: int
    ) -> (Optional[ListNode], Optional[ListNode]):
        curr = head

        for i in range(shift_count - 1):
            curr = curr.next

        head2 = curr.next
        curr.next = None

        return (head, head2)

    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        (n, shift_count) = self.calc_len_and_shift_count(head, k)

        if n <= 1 or shift_count == 0:
            return head

        (h1, h2) = self.split_into_two_list(head, shift_count)
        curr = h2

        while curr.next != None:
            curr = curr.next

        curr.next = h1

        return h2
