class Solution:
    def maxActiveSectionsAfterTrade(self, s: str) -> int:
        total_ones = 0
        prev_zeros = 0
        curr_zeros = 0
        res = 0

        for i in range(len(s)):
            match s[i]:
                case '0':
                    curr_zeros += 1
                    if prev_zeros > 0:
                        res = max(res, prev_zeros + curr_zeros)
                case '1':
                    if i > 0 and s[i - 1] == '0':
                        prev_zeros = curr_zeros
                        curr_zeros = 0

                    total_ones += 1

        return res + total_ones;
