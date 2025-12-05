class Solution:
    def countPartitions(self, nums: List[int]) -> int:
        n = len(nums)
        r_sum = sum(nums)
        l_sum = 0
        count = 0

        for i in range(n - 1):
            l_sum += nums[i]
            r_sum -= nums[i]

            if (r_sum - l_sum) % 2 == 0:
                count += 1

        return count
