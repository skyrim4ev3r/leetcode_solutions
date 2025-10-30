class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        index_neg = 1
        index_pos = 0

        res = [0] * len(nums)

        for num in nums:
            if num < 0:
                res[index_neg] = num
                index_neg += 2
            else:
                res[index_pos] = num
                index_pos += 2

        return res
