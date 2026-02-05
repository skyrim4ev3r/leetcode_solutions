MOD_TO = 1_000_000_007

class Solution:
    def sumDistance(self, nums: List[int], s: str, d: int) -> int:
        n = len(nums)

        for i in range(n):
            if s[i] == 'R':
                nums[i] += d
            else:
                nums[i] -= d

        nums.sort()

        res = 0
        prefix = 0

        for i in range(1, n):
            prefix += i * abs(nums[i] - nums[i - 1])
            res = (res + prefix) % MOD_TO

        return res
