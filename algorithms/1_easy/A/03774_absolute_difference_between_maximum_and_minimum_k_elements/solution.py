class Solution:
    def absDifference(self, nums: List[int], k: int) -> int:
        n = len(nums)

        if n == k:
            return 0

        nums.sort()
        sum_k_largest = 0
        sum_k_smallet = 0

        for i in range(n - k, n):
            sum_k_largest += nums[i]

        for i in range(k):
            sum_k_smallet += nums[i]

        return abs(sum_k_largest - sum_k_smallet)
