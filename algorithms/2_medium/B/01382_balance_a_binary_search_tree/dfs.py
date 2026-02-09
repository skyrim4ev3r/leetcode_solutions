# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs_tree_to_vec(self, curr: Optional[TreeNode], res: List[TreeNode]):
        if curr == None:
            return

        self.dfs_tree_to_vec(curr.left, res)
        res.append(curr)
        self.dfs_tree_to_vec(curr.right, res)

    def dfs_vec_to_balance_tree(
        self,
        res: List[TreeNode],
        left: int,
        right: int,
        n: int,
    ) ->  Optional[TreeNode]:
        if left < 0 or right < 0 or right >= n or left >= n or left > right:
            return None

        mid = left + (right - left) // 2
        node = res[mid]
        node.left = self.dfs_vec_to_balance_tree(res, left, mid - 1, n)
        node.right = self.dfs_vec_to_balance_tree(res, mid + 1, right, n)

        return node

    def balanceBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        res = []
        self.dfs_tree_to_vec(root, res)

        n = len(res)
        left = 0
        right = n - 1

        return self.dfs_vec_to_balance_tree(res, left, right, n)
