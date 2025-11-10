class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        nums_len = len(nums)

        if nums_len <= 3 or nums[0] >= nums[1] or nums[-2] >= nums[-1]:
            return False

        change_count = 0
        is_increasing = True

        for i in range(1, nums_len):
            if change_count > 2 or nums[i] == nums[i - 1]:
                return False

            if (nums[i] > nums[i - 1]) != is_increasing:
                is_increasing = not is_increasing
                change_count += 1

        return change_count == 2
