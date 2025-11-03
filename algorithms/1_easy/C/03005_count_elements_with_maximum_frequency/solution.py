class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        freqs = dict(Counter(nums))

        max_freq = 0
        total = 0

        for freq in freqs.values():
            if freq > max_freq:
                total = freq
                max_freq = freq
            elif freq == max_freq:
                total += freq

        return total
