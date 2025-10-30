class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:

        count = 0
        total_sum = 0
        left = 0
        right = 0
        nums_len = len(nums)

        while left < nums_len:
            while right < nums_len and (total_sum + nums[right]) * (right - left + 1) < k:
                total_sum += nums[right]
                right += 1

            count += right - left

            total_sum -= nums[left]
            left += 1

            if right < left:
                right = left
                total_sum = 0

        return count
