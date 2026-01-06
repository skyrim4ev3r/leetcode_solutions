class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        n = len(nums1)
        hashmap = defaultdict(int)
        count = 0

        for i3 in range(n):
            for i4 in range(n):
                hashmap[nums3[i3] + nums4[i4]] += 1

        for i1 in range(n):
            for i2 in range(n):
                s = nums1[i1] + nums2[i2]
                other = -s
                val = hashmap.get(other)

                if val != None:
                    count += val

        return count
