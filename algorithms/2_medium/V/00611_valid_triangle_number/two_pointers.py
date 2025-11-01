class Solution:
    def triangleNumber(self, nums: List[int]) -> int:

        total_sum = 0
        nums_len = len(nums)

        nums.sort()

        for i in range(2, nums_len):

            left = 0
            right = i - 1

            while left < right:
                if nums[left] + nums[right] > nums[i]:
                    # Add all triplets
                    # nums[left..=right - 1], nums[right], nums[i]
                    total_sum += right - left
                    right -= 1
                else:
                    left += 1

        return total_sum
