class Solution:
    def sumIndicesWithKSetBits(self, nums: List[int], k: int) -> int:

        total_sum = 0
        nums_len = len(nums)

        for i in range(nums_len):
            if bin(i).count('1') == k:
                total_sum += nums[i]

        return total_sum
