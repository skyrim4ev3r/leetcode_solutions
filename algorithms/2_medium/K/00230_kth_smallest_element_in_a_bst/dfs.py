# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, curr: Optional[TreeNode], k: int):
        if curr == None or self.count > k:
            return

        self.dfs(curr.left, k)

        self.count += 1

        if self.count == k:
            self.res = curr.val

        self.dfs(curr.right, k)

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        self.res = 0
        self.count = 0

        self.dfs(root, k)

        return self.res
