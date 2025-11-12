# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrderBottom(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []

        if root == None:
            return res

        v1 = []
        v2 = []
        v1.append(root)

        while v1:

            tmp = []
            for node in v1:
                tmp.append(node.val)
                if node.left != None:
                    v2.append(node.left)

                if node.right != None:
                    v2.append(node.right)

            res.append(tmp)
            v1 = v2
            v2 = []

        res.reverse()

        return res
