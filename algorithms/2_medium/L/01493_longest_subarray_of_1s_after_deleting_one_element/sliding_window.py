class Solution:
    def longestSubarray(self, nums: List[int]) -> int:

        left = 0
        zero_count = 0
        max_subarr_len = 0
        nums_len = len(nums)

        for right in range(nums_len):
            if nums[right] == 0:
                zero_count += 1

            while zero_count > 1:
                if nums[left] == 0:
                    zero_count -= 1

                left += 1

            max_subarr_len = max(max_subarr_len, right - left + 1 - zero_count)

        # Edge case: if entire arr is 1, then max_subarr_len will be equal to len
        # need to delete at least one of them
        if max_subarr_len == nums_len:
            return max_subarr_len - 1

        return max_subarr_len
