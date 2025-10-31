class Solution:
    def majorityElement(self, nums: List[int]) -> int:

        freqs = {}
        max_freq_num = 0
        max_freq_count = 0

        for num in nums:
            if num in freqs:
                freqs[num] += 1
            else:
                freqs[num] = 1

        for (num, freq) in freqs.items():
            if freq > max_freq_count:
                max_freq_count = freq
                max_freq_num = num

        return max_freq_num
