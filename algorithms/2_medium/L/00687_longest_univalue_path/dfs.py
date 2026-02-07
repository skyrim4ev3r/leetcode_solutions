# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, curr: Optional[TreeNode], parent_val: int) -> int:
        if curr == None:
            return 0

        left_child_path = self.dfs(curr.left, curr.val)
        right_child_path = self.dfs(curr.right, curr.val)
        self.max_path = max(self.max_path, 1 + left_child_path + right_child_path)

        if curr.val == parent_val:
            return 1 + max(left_child_path, right_child_path)
        else:
            return 0

    def longestUnivaluePath(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0

        self.max_path = 0
        self.dfs(root, 0)

        max_path_edges = self.max_path - 1

        return max_path_edges
