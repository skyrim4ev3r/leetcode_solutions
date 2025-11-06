class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        hashset = set(nums)
        max_val = max(nums)
        min_val = min(nums)
        res = []

        for val in range(min_val, max_val):
            if not val in hashset:
                res.append(val)

        return res
