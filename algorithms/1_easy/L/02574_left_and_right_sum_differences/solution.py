class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        sum_to_right = sum(nums)
        sum_to_left = 0
 
        for i in range(len(nums) - 1, -1, -1):
            original_val = nums[i]
            sum_to_right -= original_val
            nums[i] = abs(sum_to_right - sum_to_left)
            sum_to_left += original_val

        return nums
