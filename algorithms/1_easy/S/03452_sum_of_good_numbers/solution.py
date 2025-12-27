class Solution:
    def sumOfGoodNumbers(self, nums: List[int], k: int) -> int:
        res = 0
        n = len(nums)

        for i in range(n):
            if (
                (i < k or nums[i - k] < nums[i]) and
                (i + k >= n or nums[i + k] < nums[i])
            ):
                res += nums[i]

        return res
