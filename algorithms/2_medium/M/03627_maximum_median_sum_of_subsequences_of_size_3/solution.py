"""
    1- Sort array
    2- Choose two largest and one smallest for each sub-array, and second largest will be median
    3- Add 2nd largest to sum as median

    after sort array of len equal to n
    the first n/3 nums are smalles, so skip(n/3)
    indices with odd difference with n/3 like (n/3)+1, (n/3)+3... are indices of first largest values
    indice with even difference of n/3 include n/3 itself are second largest values indices:
    (n/3)+0, (n/3)+2,..
    so simply after .skip(n/3).step_by(2) to select even nums
    then map() to map them to i64
    and then sum()
"""

class Solution:
    def maximumMedianSum(self, nums: List[int]) -> int:
       return sum(sorted(nums)[(len(nums)//3)::2])