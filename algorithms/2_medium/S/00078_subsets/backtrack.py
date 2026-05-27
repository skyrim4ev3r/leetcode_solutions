class Solution:
    def backtrack(self, nums, nums_len, nums_idx, res, curr_vec):
        if nums_idx == nums_len:
            res.append(curr_vec[:])
            return

        self.backtrack(nums, nums_len, nums_idx + 1, res, curr_vec)
        curr_vec.append(nums[nums_idx])
        self.backtrack(nums, nums_len, nums_idx + 1, res, curr_vec)
        curr_vec.pop()

    def subsets(self, nums: List[int]) -> List[List[int]]:
        nums_len = len(nums)
        nums_idx = 0
        res = []
        curr_vec = []

        self.backtrack(nums, nums_len, nums_idx, res, curr_vec)

        return res
