# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

INT_MIN = -sys.maxsize - 1

class Solution:
    def dfs(self, curr_node, max_val):
        if curr_node == None:
            return 0

        total_sum = 0

        if  max_val <= curr_node.val:
            total_sum = 1
            max_val = curr_node.val

        total_sum += self.dfs(curr_node.left, max_val)
        total_sum += self.dfs(curr_node.right, max_val)

        return total_sum

    def goodNodes(self, root: TreeNode) -> int:
        max_val = INT_MIN

        return self.dfs(root, max_val)
