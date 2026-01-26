class Solution:
    def minOperations(self, nums: List[int], target: List[int]) -> int:
        n = len(nums)
        hashset =  set()

        for i in range(n):
            if nums[i] != target[i]:
                hashset.add(nums[i])

        return len(hashset)
