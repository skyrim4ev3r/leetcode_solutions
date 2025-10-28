class Solution:
    def minimumSumSubarray(self, nums: List[int], min_width: int, max_width: int) -> int:
        min_positive_sum = -1
        n = len(nums)

        for width in range(min_width, max_width + 1):
            left = 0
            right = width - 1
            curr_sum = sum(nums[left:right + 1])
    
            while right < n:
                if curr_sum > 0 and (curr_sum < min_positive_sum or min_positive_sum == -1):
                    min_positive_sum = curr_sum

                right += 1
                if right < n:
                    curr_sum += nums[right]
                    curr_sum -= nums[left]
                    left += 1

        return min_positive_sum
