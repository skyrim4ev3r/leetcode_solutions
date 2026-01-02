class Solution:
    def countKConstraintSubstrings(self, s: str, k: int) -> int:
        n = len(s)
        left = 0
        count = 0
        zeros = 0
        ones = 0

        for right in range(n):
            if s[right] == '0':
                zeros += 1
            else:
                ones += 1

            while ones > k and zeros > k:
                if s[left] == '0':
                    zeros -= 1
                else:
                    ones -= 1
                left += 1

            count += right - left + 1

        return count
