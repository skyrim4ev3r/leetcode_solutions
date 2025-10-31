# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorder_traversal_helper(self, res, curr_node):

        if curr_node == None:
            return

        self.inorder_traversal_helper(res, curr_node.left)

        res.append(curr_node.val)

        self.inorder_traversal_helper(res, curr_node.right)

    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []

        self.inorder_traversal_helper(res, root)

        return res
