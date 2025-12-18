class Solution:
    def getXORSum(self, arr1: List[int], arr2: List[int]) -> int:
        return reduce(xor, arr1) & reduce(xor, arr2)
