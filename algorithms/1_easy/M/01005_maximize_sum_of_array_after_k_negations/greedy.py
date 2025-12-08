class Solution:
    def largestSumAfterKNegations(self, nums: List[int], k: int) -> int:
        nums.sort()

        n = len(nums)
        curr_index = 0

        while curr_index < n and nums[curr_index] < 0 and k > 0:
            nums[curr_index] *= -1
            k -= 1
            curr_index += 1

        res = sum(nums)

        if k % 2 == 0:
            return res

        return res - 2 * min(nums)
