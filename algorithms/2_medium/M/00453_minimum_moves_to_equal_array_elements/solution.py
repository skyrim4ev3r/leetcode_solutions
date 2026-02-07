class Solution:
    def minMoves(self, nums: List[int]) -> int:
        min_elem = min(nums)
        count = 0

        for num in nums:
            count += num - min_elem

        return count
