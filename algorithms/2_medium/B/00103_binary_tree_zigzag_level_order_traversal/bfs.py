# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root == None:
            return []

        res = []
        q = deque()
        q.append(root)
        flip_flop = False

        while q:
            n = len(q)
            temp = []

            for _ in range(n):
                node = q.popleft()
                temp.append(node.val)

                if node.left != None:
                    q.append(node.left)

                if node.right != None:
                    q.append(node.right)

            if flip_flop:
                temp.reverse()

            res.append(temp)
            flip_flop = not flip_flop

        return res
