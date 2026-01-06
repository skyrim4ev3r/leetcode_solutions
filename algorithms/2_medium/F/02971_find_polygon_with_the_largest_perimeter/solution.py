class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort()
        total_sum = sum(nums)

        for i in range(len(nums) - 1, 1, -1):
            largest_side = nums[i]

            if largest_side * 2 < total_sum:
                return total_sum

            total_sum -= largest_side

        return -1
