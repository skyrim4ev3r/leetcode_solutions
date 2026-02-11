class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        pairs.sort(key= lambda x: x[1])

        curr_end = pairs[0][1]
        count = 1

        for p in pairs:
            if p[0] > curr_end:
                curr_end = p[1]
                count += 1

        return count
