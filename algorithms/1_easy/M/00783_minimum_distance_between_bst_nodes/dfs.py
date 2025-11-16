# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, curr):
        val = curr.val
        min_val = val
        max_val = val

        if curr.left != None:
            left_res = self.dfs(curr.left)
            self.min_diff = min(self.min_diff, val - left_res[1])
            min_val = left_res[0]

        if curr.right != None:
            right_res = self.dfs(curr.right)
            self.min_diff = min(self.min_diff, right_res[0] - val)
            max_val = right_res[1]

        return (min_val, max_val)

    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        self.min_diff = sys.maxsize

        self.dfs(root)

        return self.min_diff
