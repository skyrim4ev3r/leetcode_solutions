INT_MAX = sys.maxsize

class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        mid_val = INT_MAX
        min_val = INT_MAX

        for curr_val in nums:
            if curr_val > mid_val:
                return True

            if curr_val < min_val:
                min_val = curr_val
            elif curr_val > min_val and curr_val < mid_val:
                mid_val = curr_val

        return False
