class Solution:
    def minOperations(self, nums: List[int]) -> int:
        return 1 if any(num != nums[0] for num in nums) else 0
