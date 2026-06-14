# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def pairSum(self, head: Optional[ListNode]) -> int:
        arr = []
        while head != None:
            arr.append(head.val)
            head = head.next

        l = 0
        r = len(arr) - 1
        max_sum = 0

        while l < r:
            max_sum = max(max_sum, arr[l] + arr[r])
            l += 1
            r -= 1

        return max_sum
