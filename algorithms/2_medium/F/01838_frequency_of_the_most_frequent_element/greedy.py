class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        nums.sort()

        curr_cost = 0
        left = 0
        max_width = 1
        n = len(nums)

        for right in range(n):
            inc_amount = nums[right] - nums[right - 1]
            count_prev_nums = right - left

            curr_cost += inc_amount * count_prev_nums;

            while curr_cost > k:
                curr_cost -= nums[right] - nums[left]
                left += 1

            max_width = max(max_width, right - left + 1)

        return max_width
