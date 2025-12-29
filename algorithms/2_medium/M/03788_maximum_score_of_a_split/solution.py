class Solution:
    def maximumScore(self, nums: List[int]) -> int:
        n = len(nums)
        min_suffix = [0] * n
        min_suffix[n - 1] = nums[n - 1]

        for i in range(n - 2, -1, -1):
            min_suffix[i] = min(min_suffix[i + 1], nums[i])

        prefix = 0
        max_score = -sys.maxsize - 1

        for i in range(n - 1):
            prefix += nums[i]
            max_score = max(max_score, prefix - min_suffix[i + 1])

        return max_score
