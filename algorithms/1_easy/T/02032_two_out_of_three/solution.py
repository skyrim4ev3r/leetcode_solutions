class Solution:
    def twoOutOfThree(self, nums1: List[int], nums2: List[int], nums3: List[int]) -> List[int]:
        num_map = {}
        res = []

        for num in nums1:
            if num in num_map:
                continue
                #num_map[num] |= 1
            else:
                num_map[num] = 1
        
        for num in nums2:
            if num in num_map:
                num_map[num] |= 2
            else:
                num_map[num] = 2

        for num in nums3:
            if num in num_map:
                num_map[num] |= 4
            else:
                continue;
                #num_map[num] = 4

        for (key, val) in num_map.items():
            if bin(val).count('1') > 1:
                res.append(key)

        return res
