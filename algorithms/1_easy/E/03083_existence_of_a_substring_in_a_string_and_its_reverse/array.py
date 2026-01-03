class Solution:
    def isSubstringPresent(self, s: str) -> bool:
        n = len(s)
        seen = [[False] * 26 for _ in range(26)]

        for s_index in range(1, n):
            i = ord(s[s_index - 1]) - ord('a')
            j = ord(s[s_index ]) - ord('a')

            seen[i][j] = True

            if seen[j][i]:
                return True

        return False
