class Solution:
    def getMaximumXor(self, nums: List[int], maximum_bit: int) -> List[int]:
        assert(maximum_bit <= 20 and maximum_bit >= 0)
        mask = (2 ** maximum_bit) - 1;
        xor = 0
        n = len(nums)
        res = [0] * n

        for i in range(n):
            xor ^= nums[i]
            res[i] = mask ^ xor

        res.reverse()
        return res
