class Solution:
    def findClosestNumber(self, nums: List[int]) -> int:
        res = sys.maxsize

        for num in nums:
            if abs(num) < abs(res):
                res = num
            elif abs(num) == abs(res):
                res = max(res, num)

        return res
