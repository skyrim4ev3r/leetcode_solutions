# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def travers(self, node, arr):
        if node == None:
            return
        self.travers(node.left, arr)
        arr.append(node.val)
        self.travers(node.right, arr)

    def getAllElements(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> List[int]:
        vec1 = []
        vec2 = []

        self.travers(root1, vec1)
        self.travers(root2, vec2)

        vec1_len = len(vec1)
        vec2_len = len(vec2)
        res = []

        i1 = 0
        i2 = 0

        while i1 < vec1_len and i2 < vec2_len:
            if vec1[i1] <= vec2[i2]:
                res.append(vec1[i1])
                i1 += 1
            else:
                res.append(vec2[i2])
                i2 += 1

        while i1 < vec1_len:
            res.append(vec1[i1])
            i1 += 1

        while i2 < vec2_len:
            res.append(vec2[i2])
            i2 += 1

        return res
