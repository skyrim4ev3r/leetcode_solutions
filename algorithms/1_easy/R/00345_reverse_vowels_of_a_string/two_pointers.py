class Solution:
    def reverseVowels(self, s: str) -> str:
        s_list = list(s)
        lo = 0
        hi = len(s_list) - 1
        vowels = "aeiouAEIOU"

        while lo < hi:
            while lo < hi and not s_list[hi] in vowels:
                hi -= 1

            while lo < hi and not s_list[lo] in vowels:
                lo += 1

            temp = s_list[lo]
            s_list[lo] = s_list[hi]
            s_list[hi] = temp

            hi -= 1
            lo += 1

        return "".join(s_list)
