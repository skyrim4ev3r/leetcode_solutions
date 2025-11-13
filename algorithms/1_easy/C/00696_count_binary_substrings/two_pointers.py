class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        s_len = len(s)
        count = 0

        for i in range(s_len - 1):
            left = i
            right = i + 1

            if s[left] != s[right]:
                while left >= 0 and right < s_len:
                    count += 1

                    if left > 0 and s[left - 1] == s[left] and right < s_len - 1 and s[right] == s[right + 1]:
                        left -= 1
                        right += 1
                    else:
                        break

        return count
