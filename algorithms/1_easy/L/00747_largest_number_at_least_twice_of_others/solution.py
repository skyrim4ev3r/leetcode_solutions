INT_MIN = -sys.maxsize - 1;

class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        
        max1 = INT_MIN
        max2 = INT_MIN
        max1_index = -1
        nums_len = len(nums)

        for i in range(nums_len):
            if nums[i] >= max1:
                max2 = max1
                max1 = nums[i]
                max1_index = i
            elif nums[i] >= max2:
                max2 = nums[i]

        if max2 * 2 <= max1:
            return max1_index

        return -1
