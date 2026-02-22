class Solution:
    def findLHS(self, nums: List[int]) -> int:
        n = len(nums)
        freqs = defaultdict(int)

        for num in nums:
            freqs[num] += 1

        longest = 0

        for (val, freq) in freqs.items():
            next_val = freqs.get(val + 1)
            if next_val != None:
                longest = max(longest, freq + next_val)

            prev_val = freqs.get(val - 1)
            if prev_val != None:
                longest = max(longest, freq + prev_val)

        return longest
