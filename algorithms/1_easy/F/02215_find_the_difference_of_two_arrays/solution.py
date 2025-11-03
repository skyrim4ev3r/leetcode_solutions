class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        set1 = set(nums1)
        set2 = set(nums2)

        v1 = []
        v2 = []

        for num in set1:
            if not num in set2:
                v1.append(num)

        for num in set2:
            if not num in set1:
                v2.append(num)

        return [v1, v2]
