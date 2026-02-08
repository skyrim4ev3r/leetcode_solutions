class Solution:
    def countKDifference(self, nums: List[int], k: int) -> int:
        freqs = defaultdict(int)
        count = 0

        for num in nums:
            val1 = freqs.get(num - k)
            if val1 != None:
                count += val1

            val2 = freqs.get(num + k)
            if val2 != None:
                count += val2

            freqs[num] += 1

        return count
