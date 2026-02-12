"""
    1- Sort array
    2- Choose two largest and one smallest for each sub-array, and second largest will be median
    3- Add 2nd largest to sum as median
"""

class Solution:
    def maximumMedianSum(self, nums: List[int]) -> int:
       return sum(sorted(nums)[(len(nums)//3)::2])
