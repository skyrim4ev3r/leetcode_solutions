INT_MIN = -(2 ** 31) - 1

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameter_of_binary_tree_helper(self, curr_node, max_path):

        if curr_node == None:
            return 0

        left_path_len = self.diameter_of_binary_tree_helper(curr_node.left, max_path)
        right_path_len = self.diameter_of_binary_tree_helper(curr_node.right, max_path)

        curr_node_path = 1 + left_path_len + right_path_len

        max_path[0] = max(max_path[0], curr_node_path)

        return 1 + max(left_path_len, right_path_len)

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        max_path = [INT_MIN]

        self.diameter_of_binary_tree_helper(root, max_path)

        # Subtract 1 because the diameter is defined as the number of edges, 
        # which is one less than the number of nodes in the longest path.
        return max_path[0] - 1
