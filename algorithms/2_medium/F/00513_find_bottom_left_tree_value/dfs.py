# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, curr_node, curr_row):
        if curr_node == None:
            return

        if curr_row > self.selected_row:
            self.selected_row = curr_row
            self.selected_left_val = curr_node.val

        self.dfs(curr_node.left, curr_row + 1)
        self.dfs(curr_node.right, curr_row + 1)

    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        self.selected_row = -1
        self.selected_left_val = -1

        self.dfs(root, 0)

        return self.selected_left_val
