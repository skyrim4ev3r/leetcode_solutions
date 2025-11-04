class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        nums_len = len(nums)
        for i in range(nums_len):
            nums[i] *= nums[i]

        left = 0
        right = nums_len - 1
        res = [0] * nums_len
        res_index = nums_len - 1

        while left <= right:
            if nums[left] < nums[right]:
                res[res_index] = nums[right]
                right -= 1
            else:
                res[res_index] = nums[left]
                left += 1

            res_index -= 1

        return res
