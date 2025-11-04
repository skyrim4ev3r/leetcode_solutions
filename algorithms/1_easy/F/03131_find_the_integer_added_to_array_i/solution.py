INT_MAX = sys.maxsize

class Solution:
    def addedInteger(self, nums1: List[int], nums2: List[int]) -> int:
        min1 = INT_MAX
        min2 = INT_MAX

        for num in nums1:
            if num < min1:
                min1 = num

        for num in nums2:
            if num < min2:
                min2 = num

        return min2 - min1
