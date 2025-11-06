class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        freqs = defaultdict(int)
        max_freq = 0

        for num in nums:
            freqs[num] += 1

        for (_, freq) in freqs.items():
            max_freq = max(max_freq, freq)

        res = [[] for _ in range(max_freq)]

        for (num, freq) in freqs.items():
            for i in range(freq):
                res[i].append(num)

        return res
