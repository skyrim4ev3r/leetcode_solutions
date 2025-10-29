class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:

        left = 0
        nums_len = len(nums)
        count_zeros = 0
        max_width = 0

        for right in range(nums_len):
            if nums[right] == 0:
                count_zeros += 1

            while count_zeros > k:
                if nums[left] == 0:
                    count_zeros -= 1

                left += 1

            if left <= right:
                max_width = max(max_width, right - left + 1)

        return max_width
