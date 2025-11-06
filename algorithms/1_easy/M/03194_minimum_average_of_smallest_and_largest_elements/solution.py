class Solution:
    def minimumAverage(self, nums: List[int]) -> float:
        l = 0
        r = len(nums) - 1
        avg_min = 100000000000.0

        nums.sort()

        while l < r:
            avg_min = min(avg_min, (nums[l] + nums[r]) / 2)
            r -= 1
            l += 1

        return avg_min
