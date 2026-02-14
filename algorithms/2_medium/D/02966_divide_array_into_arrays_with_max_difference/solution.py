class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        n = len(nums)

        if n < 3 or n % 3 != 0:
            return []

        nums.sort()

        for i in range(0, n, 3):
            if nums[i + 2] - nums[i] > k:
                return []

        res = []

        for i in range(0, n, 3):
            res.append(nums[i : i + 3])

        return res
