class Solution:
    def sumDivisibleByK(self, nums: List[int], k: int) -> int:
        return sum([key * val for (key, val) in Counter(nums).items() if val % k == 0])
