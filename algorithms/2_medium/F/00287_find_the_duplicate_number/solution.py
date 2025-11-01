class Solution:
    def findDuplicate(self, nums: List[int]) -> int:

        res = -1
        nums_len = len(nums)
        index = 0

        while index < nums_len:
            num_as_index = abs(nums[index]) - 1

            if nums[num_as_index] > 0:
                nums[num_as_index] *= -1
            else:
                res = abs(nums[index])
                break

            index += 1

        for i in range(index):
            num_as_index = abs(nums[i]) - 1
            nums[num_as_index] *= -1

        return res
