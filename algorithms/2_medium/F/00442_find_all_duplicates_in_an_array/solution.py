class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        res = []
        nums_len = len(nums)

        for i in range(nums_len):
            num_as_index = abs(nums[i]) - 1

            if nums[num_as_index] < 0:
                res.append(abs(nums[i]))
            else:
                nums[num_as_index] *= -1

        return res
