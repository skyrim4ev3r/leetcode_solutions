# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, curr: Optional[TreeNode], freqs: Dict[int , int]):
        if curr == None:
            return

        if curr.val in freqs:
            freqs[curr.val] += 1
        else:
            freqs[curr.val] = 1

        self.dfs(curr.left, freqs)
        self.dfs(curr.right, freqs)

    def init_freqs(self, root: Optional[TreeNode]) -> Dict[int , int]:
        freqs = {}
        self.dfs(root, freqs)
        return freqs

    def max_freq(self, freqs: Dict[int , int]) -> int:
        max_freq = 0

        for (_, freq) in freqs.items():
            if freq > max_freq:
                max_freq = freq

        return max_freq

    def calc_res(self, freqs: Dict[int , int], max_freq: int) -> List[int]:
        res = []

        for (val, freq) in freqs.items():
            if freq == max_freq:
                res.append(val)

        return res

    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        freqs = self.init_freqs(root)
        max_freq = self.max_freq(freqs)
        res = self.calc_res(freqs, max_freq)

        return res
