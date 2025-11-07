class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        for (index, val) in enumerate(nums):
            dig_sum = 0

            while val > 0 :
                dig_sum += val%10
                val //=10
            if index == dig_sum : 
                return index

        return -1
