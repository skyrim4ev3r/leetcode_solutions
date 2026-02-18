class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        s.sort()
        g.sort()

        len_s = len(s)
        len_g = len(g)
        count = 0
        index_g = 0
        index_s = 0

        while index_s < len_s and index_g < len_g:
            if g[index_g] <= s[index_s]:
                count += 1
                index_g += 1

            index_s += 1

        return count
