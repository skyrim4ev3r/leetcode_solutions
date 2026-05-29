# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, curr_node, min_val, max_val) -> bool:
        if curr_node == None:
            return True

        return curr_node.val > min_val and curr_node.val < max_val and \
               self.dfs(curr_node.left, min_val, curr_node.val) and \
               self.dfs(curr_node.right, curr_node.val, max_val)

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.dfs(root, -sys.maxsize - 1 ,sys.maxsize)
