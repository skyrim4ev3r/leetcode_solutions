# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, curr: TreeNode) -> (int, int):
        curr_val = curr.val
        curr_max = curr_val
        curr_min = curr_val

        if curr.left != None:
            (left_min, left_max) = self.dfs(curr.left)
            curr_min = min(curr_min, left_min)
            curr_max = max(curr_max, left_max)

        if curr.right != None:
            (right_min, right_max) = self.dfs(curr.right)
            curr_min = min(curr_min, right_min)
            curr_max = max(curr_max, right_max)

        self.max_diff = max(self.max_diff, curr_val - curr_min, curr_max - curr_val)

        return (curr_min, curr_max)

    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        self.max_diff = -sys.maxsize - 1

        if root != None:
            self.dfs(root)

        return self.max_diff
