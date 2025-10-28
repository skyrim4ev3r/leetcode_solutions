class Solution:
    def sumDivisibleByK(self, nums: List[int], k: int) -> int:
        total_sum = 0

        for (key, val) in Counter(nums).items():
            if val % k == 0:
                total_sum += key * val

        return total_sum
