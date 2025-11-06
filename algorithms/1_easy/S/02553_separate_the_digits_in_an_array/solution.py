class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        res = []

        for num in nums:
            p = 1
            while p <= num:
                p *= 10

            p //= 10

            while p > 0:
                res.append((num // p) % 10)
                p //= 10

        return res
