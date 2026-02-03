class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        hashmap = defaultdict(int)
        n = len(nums)

        for i in range(n):
            for j in range(i + 1, n):
                hashmap[nums[i] * nums[j]] += 1

        res = 0

        for (_, freq) in hashmap.items():
            res += ((freq * (freq - 1)) // 2) * 8

        return res
