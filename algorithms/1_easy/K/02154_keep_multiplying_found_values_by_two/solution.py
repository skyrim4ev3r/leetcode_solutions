class Solution:
    def findFinalValue(self, nums: List[int], original: int) -> int:
        exact = set(nums)

        while original in exact:
            original *= 2

        return original
