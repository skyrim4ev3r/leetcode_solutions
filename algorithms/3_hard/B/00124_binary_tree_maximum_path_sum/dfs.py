# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

INT_MIN = -(2 ** 31) - 1

class Solution:
    def dfs_calculate_max_path_sum(self, curr_node,max_path_sum):

        if curr_node == None:
            return 0

        curr_val = curr_node.val
        left_max_path_sum = max(0, self.dfs_calculate_max_path_sum(curr_node.left, max_path_sum))
        right_max_path_sum = max(0, self.dfs_calculate_max_path_sum(curr_node.right, max_path_sum))

        path_sum_from_curr = curr_val + left_max_path_sum + right_max_path_sum

        max_path_sum[0] = max(max_path_sum[0], path_sum_from_curr)

        return curr_val + max(left_max_path_sum, right_max_path_sum)

    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        max_path_sum = [INT_MIN]

        self.dfs_calculate_max_path_sum(root, max_path_sum)

        return max_path_sum[0]
