class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        count, i, j = 0, 0, 0
        g.sort()
        s.sort()
        while  i < len(s) and j < len(g):
            if g[j] <= s[i]:
                count += 1
                j += 1
            i += 1
        return count
