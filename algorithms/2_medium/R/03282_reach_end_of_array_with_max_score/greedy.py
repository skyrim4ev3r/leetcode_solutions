class Solution:
    def findMaximumScore(self, nums: List[int]) -> int:
        curr_max = 0
        score = 0

        for num in nums:
            score += curr_max
            curr_max = max(curr_max, num)

        return score
