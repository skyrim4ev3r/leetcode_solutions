# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, curr):
        if curr == None:
            return False

        if curr.val == 0:
            return False

        if curr.val == 1:
            return True

        if curr.val == 2:
            return self.dfs(curr.left) or self.dfs(curr.right)

        return self.dfs(curr.left) and self.dfs(curr.right)
    def evaluateTree(self, root: Optional[TreeNode]) -> bool:
        return self.dfs(root)
