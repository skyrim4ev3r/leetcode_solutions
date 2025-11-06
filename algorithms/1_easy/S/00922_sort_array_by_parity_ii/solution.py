class Solution:
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:

        odd_index = 1
        even_index = 0
        nums_len = len(nums)

        while odd_index < nums_len and even_index < nums_len:
            while odd_index < nums_len and (nums[odd_index] & 1) == 1:
                odd_index += 2

            while even_index < nums_len and (nums[even_index] & 1) == 0:
                even_index += 2

            if odd_index >= nums_len and even_index >= nums_len:
                break

            tmp = nums[even_index]
            nums[even_index] = nums[odd_index]
            nums[odd_index] = tmp

            odd_index += 2
            even_index += 2

        return nums
