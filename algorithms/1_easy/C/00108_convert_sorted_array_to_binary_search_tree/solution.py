# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recursive(self, nums, l, r):
        mid = (l + r) // 2
        new_node = TreeNode(nums[mid])
        if l < mid:
            new_node.left = self.recursive(nums, l, mid - 1)

        if mid < r:
            new_node.right = self.recursive(nums, mid + 1, r)

        return new_node

    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        return self.recursive(nums, 0, len(nums) - 1)
