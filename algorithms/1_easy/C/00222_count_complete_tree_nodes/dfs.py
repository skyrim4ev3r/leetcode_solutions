# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs_count_nodes(self, curr_node):
        if curr_node == None:
            return 0

        return 1 + self.dfs_count_nodes(curr_node.left) + self.dfs_count_nodes(curr_node.right)

    def countNodes(self, root: Optional[TreeNode]) -> int:
        return self.dfs_count_nodes(root)
