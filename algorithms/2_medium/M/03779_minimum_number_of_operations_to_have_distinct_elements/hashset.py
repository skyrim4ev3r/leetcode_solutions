class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        seen = set()

        for i in range(n - 1, -1, -1):
            if nums[i] in seen:
                return (i // 3) + 1
            seen.add(nums[i])

        return 0
