class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        res = []
        nums_len = len(nums)

        for i in range(0, nums_len - 1, 2):
            res.extend([nums[i + 1]] * nums[i])

        return res
