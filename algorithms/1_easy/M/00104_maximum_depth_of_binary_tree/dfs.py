# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, curr_node, max_level, curr_level):
        if curr_node == None:
            return

        max_level[0] = max(max_level[0], curr_level)

        self.dfs(curr_node.left, max_level, curr_level + 1)
        self.dfs(curr_node.right, max_level, curr_level + 1)

    def maxDepth(self, root: Optional[TreeNode]) -> int:
        max_level = [0]

        self.dfs(root, max_level, 1)

        return max_level[0]
