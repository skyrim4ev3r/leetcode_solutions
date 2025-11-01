class Solution:
    def smallestPalindrome(self, s: str) -> str:
        s_list = list(s)
        freqs = [0] * 26

        for ch in s_list:
            freqs[ord(ch) - ord('a')] += 1

        left = 0
        right = len(s_list) - 1

        for i in range(26):
            # Input is valid, so if freq of any char be odd
            # then string len is also odd, and this char will be only char with odd freq
            if (freqs[i] & 1) == 1:
                mid = len(s) // 2
                s_list[mid] = chr(i + ord('a'))

            for _ in range(freqs[i] // 2):
                s_list[left] = chr(i + ord('a'))
                s_list[right] = chr(i + ord('a'))
                left += 1
                right -= 1

        return "".join(s_list)
