class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:

        nums.sort()

        nums_len = len(nums)
        max_freq = 0

        num_min = nums[0]
        num_max = nums[nums_len - 1]

        for num in range(num_min, num_max + 1):
            free_cost_left = bisect.bisect_left(nums, num)
            free_cost_right = bisect.bisect_right(nums, num)
            total_free_cost = free_cost_right - free_cost_left

            left = bisect.bisect_left(nums, num - k)
            right = bisect.bisect_right(nums, num + k)

            total = right - left
            total_with_cost = total - total_free_cost

            curr_freq = total_free_cost + min(total_with_cost, numOperations)

            max_freq = max(max_freq, curr_freq)

        return max_freq
