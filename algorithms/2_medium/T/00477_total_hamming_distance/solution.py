BITS_COUNT = 32

class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0

        for shift in range(BITS_COUNT):
            mask = 1 << shift
            count = 0

            for num in nums:
                if (num & mask) != 0:
                    count += 1

            res += ((n - count) * count)

        return res
