# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs_height(self, curr: Optional[TreeNode]) -> int:
        if not self.is_balanced or curr == None:
            return 0

        left_height = self.dfs_height(curr.left)
        right_height = self.dfs_height(curr.right)

        if abs(left_height - right_height) > 1:
            self.is_balanced = False

        return 1 + max(left_height, right_height)

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        self.is_balanced = True
        self.dfs_height(root)

        return self.is_balanced
