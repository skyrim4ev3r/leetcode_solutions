# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invert_tree_helper(self, curr_node):

        if curr_node == None:
            return

        temp = curr_node.left
        curr_node.left = curr_node.right
        curr_node.right = temp

        self.invert_tree_helper(curr_node.left)
        self.invert_tree_helper(curr_node.right)

    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        self.invert_tree_helper(root)

        return root
