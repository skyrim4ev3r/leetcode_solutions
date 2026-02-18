# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, curr: Optional[TreeNode]) -> (int, int):
        if curr == None:
            return (0, 0)

        (l_max1, l_max2) = self.dfs(curr.left)
        (r_max1, r_max2) = self.dfs(curr.right)

        return (
            l_max2 + r_max2 + curr.val,
            max(l_max1, l_max2) + max(r_max1, r_max2)
        )

    def rob(self, root: Optional[TreeNode]) -> int:
        res = self.dfs(root)

        return max(res[0], res[1])
