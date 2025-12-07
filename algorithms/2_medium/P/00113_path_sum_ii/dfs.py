# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, res, temp, curr, target_sum, curr_sum):
        if curr == None:
            return

        curr_sum += curr.val
        temp.append(curr.val)
        if curr.left == None and curr.right == None:
            if curr_sum == target_sum:
                res.append(temp.copy())

        self.dfs(res, temp, curr.left, target_sum, curr_sum)
        self.dfs(res, temp, curr.right, target_sum, curr_sum)
        temp.pop()

    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        res = []
        temp = []
        self.dfs(res, temp, root, targetSum, 0)

        return res
