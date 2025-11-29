class Solution:
    def arithmeticTriplets(self, nums: List[int], diff: int) -> int:
        n = len(nums)
        count = 0

        for i in range(n):
            for j in range(i + 1, n):
                for k in range(j + 1, n):
                    if nums[k] - nums[j] == diff and nums[j] - nums[i] == diff:
                        count += 1

        return count
