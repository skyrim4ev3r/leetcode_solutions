class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        freqs = [[0] * 26 for _ in range(26)]
        max_len = 0

        for w in words:
            (i, j) = (ord(w[0]) - ord('a'), ord(w[1]) - ord('a'))
            (complement_i, complement_j) = (j, i)

            if freqs[complement_i][complement_j] > 0:
                # If complement_string exist then
                # Add both string & complement_string with total len of 4
                max_len += 4
                freqs[complement_i][complement_j] -= 1
            else:
                freqs[i][j] += 1

        # If self-palindrome strings are left,
        # Then we can use 1 of them as the middle part of final string.
        # Strings like: aa, bb, cc,..
        for i in range(26):
            if freqs[i][i] > 0:
                max_len += 2
                break

        return max_len
