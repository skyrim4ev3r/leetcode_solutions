class Solution:
    def countValidSelections(self, nums: List[int]) -> int:
        sum_right = sum(nums)
        sum_left = 0
        count = 0

        for num in nums:
            sum_left += num
            sum_right -= num

            if num == 0:
                if sum_left == sum_right:
                    count += 2
                elif abs(sum_left - sum_right) == 1:
                    count += 1

        return count
