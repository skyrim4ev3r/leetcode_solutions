class Solution:
    def search(self, nums: List[int], target: int) -> int:

        pos = bisect_left(nums, target)

        if pos == len(nums) or nums[pos] != target:
            return -1

        return pos
