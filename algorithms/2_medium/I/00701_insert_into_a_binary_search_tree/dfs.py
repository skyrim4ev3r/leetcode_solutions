# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs_insert(self, curr: TreeNode, val: int):
        if curr.val > val:
            if curr.left != None:
                self.dfs_insert(curr.left, val)
            else:
                curr.left = TreeNode(val)
        elif curr.val < val:
            if curr.right != None:
                self.dfs_insert(curr.right, val)
            else:
                curr.right = TreeNode(val)

    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if root == None:
            return TreeNode(val)

        self.dfs_insert(root, val)

        return root
