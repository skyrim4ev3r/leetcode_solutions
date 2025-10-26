INT_MAX = sys.maxsize

class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:

        prev_valid_min = INT_MAX
        curr_min = INT_MAX

        for num in nums:
            if num > prev_valid_min:
                return True

            if num > curr_min:
                prev_valid_min = min(prev_valid_min, num)
            else:
                curr_min = num

        return False
