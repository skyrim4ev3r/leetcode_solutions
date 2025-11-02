class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:

        duplicate_num = -1
        missing_num = -1
        len_nums = len(nums)

        for i in range(len_nums):
            index = abs(nums[i]) - 1
            if nums[index] < 0:
                duplicate_num = abs(nums[i])
            else:
                nums[index] *= -1

        for i in range(len_nums):
            if nums[i] > 0:
                missing_num = i + 1
                break

        return [duplicate_num, missing_num]
