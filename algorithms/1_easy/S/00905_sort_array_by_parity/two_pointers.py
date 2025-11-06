class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:

        nums_len = len(nums)
        even_index = 0
        odd_index = nums_len - 1

        while True:
            while even_index < nums_len and (nums[even_index] & 1) == 0:
                even_index += 1

            while odd_index >= 0 and (nums[odd_index] & 1) == 1:
                odd_index -= 1

            if even_index >= nums_len or odd_index < 0 or even_index >= odd_index:
                break

            tmp = nums[even_index]
            nums[even_index] = nums[odd_index]
            nums[odd_index] = tmp

            odd_index -= 1
            even_index += 1

        return nums
