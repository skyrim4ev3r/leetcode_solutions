# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        vec_a = []
        vec_b = []
        curr_level = 0

        vec_a.append(root)

        while vec_a:
            if (curr_level & 1) == 1:
                left = 0
                right = len(vec_a) - 1

                while left < right:
                    temp = vec_a[left].val
                    vec_a[left].val = vec_a[right].val
                    vec_a[right].val= temp
                    right -= 1
                    left += 1

            for node in vec_a:
                if node.left != None:
                    vec_b.append(node.left)

                if node.right != None:
                    vec_b.append(node.right)

            vec_a = vec_b
            vec_b = []
            curr_level += 1

        return root
