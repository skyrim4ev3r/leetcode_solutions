class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        nums.sort()

        nums_len = len(nums)
        max_freq = left = right = left_single = right_single = left_doubled = right_doubled = 0      

        while right < nums_len:

            # First two-pointers logic
            left = right
            curr = nums[left]

            while right < nums_len and nums[right] == curr:
                right += 1

            # Second two-pointers logic
            min_single = curr - k
            max_single = curr + k

            while nums[left_single] < min_single:
                left_single += 1

            while right_single < nums_len and nums[right_single] <= max_single:
                right_single += 1

            total_free_cost = right - left
            total_with_cost = right_single - right + left - left_single
            curr_freq = total_free_cost + min(total_with_cost, numOperations)
            max_freq = max(max_freq, curr_freq)

            # Third two-pointers logic
            min_doubled = curr - (2 * k)
            max_doubled = curr + (2 * k)

            while nums[left_doubled] < min_doubled:
                left_doubled += 1

            while right_doubled < nums_len and nums[right_doubled] <= max_doubled:
                right_doubled += 1

            # Assume that all numbers in this range need operation
            # as an example [1,2,3] k = 1, op = 2
            # then while this conditions cant set max_freq higher than 2,
            # but number "2" can check it when it is candidate with prev conditions as 2 + k, 2 - k
            total_double_on_left = right - left_doubled
            max_freq = max(max_freq, min(total_double_on_left, numOperations))

            total_double_on_right = right_doubled - left
            max_freq = max(max_freq, min(total_double_on_right, numOperations))

        return max_freq
