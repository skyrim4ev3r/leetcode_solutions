# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []

        if root == None:
            return res

        current_level = []
        next_level = []

        current_level.append(root)

        while current_level:
            temp = []

            for node in current_level:
                temp.append(node.val)

                if node.left != None:
                    next_level.append(node.left)

                if node.right != None:
                    next_level.append(node.right)

            res.append(temp)
            current_level = next_level
            next_level = []

        return res
