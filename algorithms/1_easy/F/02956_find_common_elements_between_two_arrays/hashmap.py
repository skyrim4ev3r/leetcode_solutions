class Solution:
    def findIntersectionValues(self, nums1: List[int], nums2: List[int]) -> List[int]:
        map1 = Counter(nums1)
        map2 = Counter(nums2)
        count1 = 0
        count2 = 0

        for (num1, freq1) in map1.items():
            freq2 = map2.get(num1)
            if freq2 != None:
                count1 += freq1
                count2 += freq2

        return [count1, count2]
