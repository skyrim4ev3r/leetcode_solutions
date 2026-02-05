class Solution:
    def check_guess(self, nums, guess):
        op_needed = 0

        for num in nums:
            op_needed += (num + guess - 1) // guess

        return op_needed <= guess ** 2

    def minimumK(self, nums: List[int]) -> int:
        low = 1
        high = 10_000

        while low <= high:
            mid = low + (high - low) // 2

            if self.check_guess(nums, mid):
                high = mid - 1
            else:
                low = mid + 1

        return low
