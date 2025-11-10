class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:

        res = []
        nums_len = len(nums)

        for i in range(nums_len):
            res.insert(index[i], nums[i])

        return res
