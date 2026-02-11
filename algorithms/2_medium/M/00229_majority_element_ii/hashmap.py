class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        min_target_freq = 1 + len(nums) // 3
        freqs = defaultdict(int)
        res = []

        for num in nums:
            freqs[num] += 1

        for (val, freq) in freqs.items():
            if freq >= min_target_freq:
                res.append(val)

        return res
