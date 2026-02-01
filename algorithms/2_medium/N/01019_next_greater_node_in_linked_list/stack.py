# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nextLargerNodes(self, head: Optional[ListNode]) -> List[int]:
        res = []
        curr = head

        while curr != None:
            res.append(curr.val)
            curr = curr.next

        n = len(res)
        stack = []

        for i in range(n - 1, -1, -1):
            curr_val = res[i]

            while stack and stack[-1] <= curr_val:
                stack.pop()

            if not stack:
                res[i] = 0
            else:
                res[i] = stack[-1]

            stack.append(curr_val)

        return res
