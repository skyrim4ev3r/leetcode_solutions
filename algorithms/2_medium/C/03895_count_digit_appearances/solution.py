class Solution:
    def countDigitOccurrences(self, nums: list[int], digit: int) -> int:
        freq = 0

        for num in nums:
            while num > 0:
                if num % 10 == digit:
                    freq += 1
                num //= 10

        return freq
