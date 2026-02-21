class Solution:
    def splitArray(self, nums: List[int]) -> int:
        n = len(nums)

        left = 0
        while left + 1 < n and nums[left] < nums[left + 1]:
            left += 1

        right = n - 1
        while right > 0 and nums[right - 1] > nums[right]:
            right -= 1

        if left == right:
            index = left
            sum_left_part = sum(nums[:index])
            sum_right_part = sum(nums[(index + 1):])

            if index == n - 1:
                return abs(sum_left_part - nums[index])
            elif index == 0:
                return abs(nums[index] - sum_right_part)
            else:
                max_part = max(sum_left_part, sum_right_part)
                min_part = min(sum_left_part, sum_right_part)

                return abs(max_part - (min_part + nums[index]))
        elif left + 1 == right:
            sum_left_part = sum(nums[:left + 1])
            sum_right_part = sum(nums[right:])

            return abs (sum_left_part - sum_right_part)
        else:
            return -1
