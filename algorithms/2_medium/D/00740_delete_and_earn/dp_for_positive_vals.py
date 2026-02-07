class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        dp_len = 1 + max(nums)
        dp = [0] * dp_len

        for num in nums:
            dp[num] += num

        for i in range(3, dp_len):
            dp[i] += max(dp[i - 2], dp[i - 3])

        return max(dp[dp_len - 1], dp[dp_len - 2])
