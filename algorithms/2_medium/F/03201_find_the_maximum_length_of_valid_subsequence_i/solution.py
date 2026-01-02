class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        odd_count = 0
        even_count = 0
        switch_count = 0
        prev_is_even = not (nums[0] % 2 == 0)

        for num in nums:
            curr_is_even  = (num % 2 == 0)

            if curr_is_even:
                even_count += 1
            else:
                odd_count += 1

            if curr_is_even !=  prev_is_even:
                prev_is_even = curr_is_even
                switch_count += 1

        return max(switch_count, max(even_count, odd_count))
