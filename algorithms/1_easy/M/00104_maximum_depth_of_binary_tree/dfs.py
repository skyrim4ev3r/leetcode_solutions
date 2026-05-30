# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, curr_node) -> int:
        if curr_node == None:
            return 0

        return 1 + max(
            self.dfs(curr_node.left),
            self.dfs(curr_node.right)
        )

    def maxDepth(self, root: Optional[TreeNode]) -> int:
        return self.dfs(root)
