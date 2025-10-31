# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, curr_node, curr_sum, target_sum):
        if curr_node == None:
            return False

        curr_sum += curr_node.val
        is_leaf = (curr_node.left == None) and (curr_node.right == None)

        return (is_leaf and curr_sum == target_sum) or \
                self.dfs(curr_node.left, curr_sum, target_sum) or \
                self.dfs(curr_node.right, curr_sum, target_sum)

    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        return  self.dfs(root, 0, targetSum)
