INT_MAX = sys.maxsize

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, curr_node, curr_depth, min_depth):
        if curr_node == None or curr_depth >= min_depth[0]:
            return

        # Check if the current node is a leaf node
        if curr_node.left == None and curr_node.right == None:
            min_depth[0] = min(min_depth[0], curr_depth)
        else:
            #Only call dfs for children if the current node is not a leaf
            self.dfs(curr_node.left, curr_depth + 1, min_depth)
            self.dfs(curr_node.right, curr_depth + 1, min_depth)

    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0

        min_depth = [INT_MAX]

        self.dfs(root, 1, min_depth)

        return min_depth[0]
