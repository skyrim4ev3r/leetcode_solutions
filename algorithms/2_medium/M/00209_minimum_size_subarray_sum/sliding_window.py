class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n = len(nums)
        res_len =  n + 1
        left = 0
        curr_sum = 0

        for right in range(n):
            curr_sum += nums[right]

            while left <= right and curr_sum >= target:
                res_len = min(res_len, right - left + 1)
                curr_sum -= nums[left]
                left += 1

        if res_len == n + 1:
            return 0

        return res_len
