class Solution:
    def maxOperations(self, nums: List[int]) -> int:
        count = 0
        n = len(nums)
        first_sum = nums[0] + nums[1]

        for i in range(0, n, 2):
            if i + 1 < n:
                if nums[i] + nums[i + 1] != first_sum:
                    break
                count += 1

        return count
