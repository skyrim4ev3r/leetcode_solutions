class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        map1 = Counter(nums1)
        map2 = Counter(nums2)
        res = []

        for (num, count1) in map1.items():
            count2 = map2.get(num)
            if count2 != None:
                res += [num] * min(count2, count1)

        return res
