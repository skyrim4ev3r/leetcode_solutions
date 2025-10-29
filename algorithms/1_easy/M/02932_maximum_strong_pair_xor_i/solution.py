class Solution:
    def maximumStrongPairXor(self, nums: List[int]) -> int:
        res_max = 0
        nums_len = len(nums)

        for i in range(nums_len):
            for j in range(nums_len):
                if abs(nums[i] - nums[j]) <= min(nums[i], nums[j]):
                    res_max = max(res_max, nums[i] ^ nums[j])

        return res_max
