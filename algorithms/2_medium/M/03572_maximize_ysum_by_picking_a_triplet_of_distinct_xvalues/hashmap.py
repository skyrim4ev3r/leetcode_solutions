class Solution:
    def maxSumDistinctTriplet(self, x: List[int], y: List[int]) -> int:
        hashmap = {}

        for (i, val) in enumerate(x):
            if val in hashmap:
                hashmap[val] = max(hashmap[val], y[i])
            else:
                hashmap[val] = y[i]

        max1, max2, max3 = (-1, -1, -1)

        for val in hashmap.values():
            if val > max1:
                max3 = max2
                max2 = max1
                max1 = val
            elif val > max2:
                max3 = max2
                max2 = val
            elif val > max3:
                max3 = val

        if max3 == -1:
            return -1

        return max1 + max2 + max3
