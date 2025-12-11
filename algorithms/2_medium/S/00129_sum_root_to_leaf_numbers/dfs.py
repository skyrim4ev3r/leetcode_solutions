# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, curr, curr_sum):
        if curr == None:
            return 0

        if curr.left == None and curr.right == None:
            return curr_sum * 10 + curr.val

        return self.dfs(curr.left, curr_sum * 10 + curr.val) + \
               self.dfs(curr.right, curr_sum * 10 + curr.val)

    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        return self.dfs(root, 0)
