class Solution:
    def countElements(self, nums: List[int], k: int) -> int:
        n = len(nums)
        if k == 0:
            return n
        nums.sort()
        k_th_biggest = nums[n - k]

        return bisect.bisect_left(nums, k_th_biggest)
