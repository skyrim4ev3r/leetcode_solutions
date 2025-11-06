class Solution:
    def maximizeSum(self, nums: List[int], k: int) -> int:
        max_num = -1000000000
        for num in nums:
            max_num = max(max_num, num)

        return max_num * k + (k * (k - 1)) // 2
