# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, curr_node, curr_row, max_rows):
        if curr_node == None:
            return

        if curr_row >= len(max_rows):
            max_rows.append(curr_node.val)
        else:
            max_rows[curr_row] = max(max_rows[curr_row], curr_node.val)

        self.dfs(curr_node.left, curr_row + 1, max_rows)
        self.dfs(curr_node.right, curr_row + 1, max_rows)

    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        max_rows = []

        self.dfs(root, 0, max_rows)

        return max_rows
