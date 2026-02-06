class Solution:
    def rob_helper(self, dp: List[int]) -> int:
        n = len(dp)

        dp[2] += dp[0]

        for i in range(3, n):
            dp[i] += max(dp[i - 2], dp[i - 3])

        return max(dp[n - 1], dp[n - 2])

    def rob(self, nums: List[int]) -> int:
        if len(nums) <= 3:
            return max(nums)

        dp1 = nums[1:]
        dp2 = nums[:-1]

        max_dp1 = self.rob_helper(dp1)
        max_dp2 = self.rob_helper(dp2)

        return max(max_dp1, max_dp2)
