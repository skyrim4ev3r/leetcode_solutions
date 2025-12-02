class Solution:
    def numberOfPairs(self, nums: List[int]) -> List[int]:
        freqs = defaultdict(int)
        count_pair = 0
        count_leftover = 0

        for num in nums:
            freqs[num] += 1

        for freq in freqs.values():
            count_pair += freq // 2
            count_leftover += (freq & 1)

        return [count_pair, count_leftover]
