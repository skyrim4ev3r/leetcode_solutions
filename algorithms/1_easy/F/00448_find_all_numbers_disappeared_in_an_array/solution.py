class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        nums_len = len(nums)

        for i in range(nums_len):
            index = abs(nums[i]) - 1
            if nums[index] > 0:
                nums[index] *= -1

        res = []

        for i in range(nums_len):
            if nums[i] > 0:
                res.append(i + 1)

        return res
