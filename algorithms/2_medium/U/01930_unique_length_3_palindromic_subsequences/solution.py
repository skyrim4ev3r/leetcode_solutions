class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        n = len(s)
        is_seen_first = [False] * 26
        count = 0

        for i in range(n):
            if not is_seen_first[ord(s[i]) - ord('a')]:
                is_seen_first[ord(s[i]) - ord('a')] = True

                k = n - 1
                while k > i and s[k] != s[i]:
                    k -= 1

                is_seen_second =  [False] * 26

                for j in range(i + 1, k):
                    if not is_seen_second[ord(s[j]) - ord('a')]:
                        count += 1
                        is_seen_second[ord(s[j]) - ord('a')] = True

        return count
