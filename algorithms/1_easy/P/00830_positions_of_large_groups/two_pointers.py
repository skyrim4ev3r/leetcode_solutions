class Solution:
    def largeGroupPositions(self, s: str) -> List[List[int]]:
        res = []
        n = len(s)
        left = 0

        for right in range(n):
            if right == n - 1 or s[right] != s[right + 1]:
                if right - left + 1 > 2:
                    res.append([left, right])

                left = right + 1

        return res
