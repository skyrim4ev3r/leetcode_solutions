class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:

        nums_len = len(nums)
        res = [0] * nums_len

        prefix_product = 1
        for i in range(nums_len):
            res[i] = prefix_product
            prefix_product *= nums[i]

        postfix_product = 1
        for i in range(nums_len - 1, -1, -1):
            res[i] *= postfix_product
            postfix_product *= nums[i]

        return res
