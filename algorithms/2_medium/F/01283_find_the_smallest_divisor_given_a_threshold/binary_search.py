class Solution:
    def is_possible(self, nums: List[int], divisor: int, threshold: int) -> bool:
        total_sum = 0

        for num in nums:
            total_sum += (num + divisor - 1) // divisor

            if total_sum > threshold:
                return False

        return True

    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        low  = 1
        high = 1 + max(nums)

        while low <= high:
            mid = low + (high - low) // 2

            if self.is_possible(nums, mid, threshold):
                high = mid - 1
            else:
                low = mid + 1

        return low
