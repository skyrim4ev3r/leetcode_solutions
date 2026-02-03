class Solution:
    def minDifference(self, nums: List[int]) -> int:
        target_steps = 3
        n = len(nums)

        if n <= target_steps + 1:
            return 0

        nums.sort()

        min_diff = sys.maxsize

        for i in range(target_steps + 1):
            j = n - (target_steps - i) - 1
            min_diff = min(min_diff, nums[j] - nums[i])

        return min_diff
