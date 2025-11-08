class Solution:
    def maxKDistinct(self, nums: List[int], k: int) -> List[int]:
        unique_nums = set(nums)
        largest_k = sorted(unique_nums, reverse = True)[:k]
        return largest_k
