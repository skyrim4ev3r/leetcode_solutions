class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        median = nums[n // 2]
        cost = 0

        for num in nums:
            cost += abs(num - median)

        return cost
