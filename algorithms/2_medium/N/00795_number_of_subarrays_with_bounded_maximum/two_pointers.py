class Solution:
    def count_subarrays(self, nums: List[int], start: int, end: int,  max_lower_bound: int) -> int:
        if start == end:
            return 0

        width = end - start
        total_possible_subarrays = width * (width + 1) // 2
        invalid_counts = 0
        left = start

        for right in range(start, end):
            if nums[right] >= max_lower_bound:
                invalid_width = right - left
                invalid_counts += (invalid_width * (invalid_width + 1)) // 2
                left = right + 1

        invalid_width = end - left
        invalid_counts += (invalid_width * (invalid_width + 1)) // 2

        return total_possible_subarrays - invalid_counts


    def numSubarrayBoundedMax(self, nums: List[int], max_lower_bound: int, max_upper_bound: int) -> int:
        n = len(nums)
        start = 0
        count = 0

        for end in range(n):
            if nums[end] > max_upper_bound:
                count += self.count_subarrays(nums, start, end, max_lower_bound)
                start = end + 1

        count += self.count_subarrays(nums, start, n, max_lower_bound)

        return count
