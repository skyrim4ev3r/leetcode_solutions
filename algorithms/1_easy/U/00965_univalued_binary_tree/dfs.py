# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, curr, root_val):
        if curr == None:
            return True

        if curr.val != root_val:
            return False

        return self.dfs(curr.left, root_val) and self.dfs(curr.right, root_val)

    def isUnivalTree(self, root: Optional[TreeNode]) -> bool:
        return self.dfs(root, root.val)
