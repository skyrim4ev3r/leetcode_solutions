#if all numbers be equal then 0 bitwise op needed, else 1 bitwise op with range of L=0 to R=nums.size()-1
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        return int(any(num != nums[0] for num in nums))
