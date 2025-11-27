class Solution:
    def maxSubarraySum(self, nums: List[int], k: int) -> int:
        max_sum = -sys.maxsize - 1
        pref_sum = 0
        min_pref = [sys.maxsize // 2] * k
        min_pref[k - 1] = 0

        for (i, num) in enumerate(nums):
            min_pref_index = i % k

            pref_sum += num
            max_sum = max(max_sum, pref_sum - min_pref[min_pref_index])
            min_pref[min_pref_index] = min(min_pref[min_pref_index], pref_sum)

        return max_sum
