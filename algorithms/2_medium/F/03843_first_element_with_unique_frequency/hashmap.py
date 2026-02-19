class Solution:
    def firstUniqueFreq(self, nums: List[int]) -> int:
        freqs = defaultdict(int)

        for num in nums:
           freqs[num] += 1

        freqs_of_freqs = defaultdict(int)

        for freq in freqs.values():
            freqs_of_freqs[freq] += 1

        for num in nums:
            freq = freqs[num]

            if freqs_of_freqs[freq] == 1:
                return num

        return -1
