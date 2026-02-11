# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def calc_len(self, curr: Optional[ListNode]) -> int:
        n = 0
        while curr != None:
            curr = curr.next
            n += 1
        return n

    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        n = self.calc_len(head)
        seg_len1 = n // k
        extra = n % k
        curr = head
        dummy = ListNode(0)
        res = [None] * k

        for i in range(k):
            prev = dummy
            target_len = seg_len1 + (1 if extra > 0 else 0)

            if extra > 0:
                extra -= 1

            if target_len == 0:
                break

            for c in range(target_len):
                prev.next = curr
                prev = curr
                curr = curr.next
                prev.next = None

            res[i] = dummy.next
            dummy.next = None

        return res
