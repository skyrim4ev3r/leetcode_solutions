class Solution:
    def maxScore(self, s: str) -> int:
        total_ones = s.count('1')
        n = len(s)
        curr_ones = 0
        curr_zeros = 0
        max_score = 0

        for i in range(n - 1):
            if s[i] == '0':
                curr_zeros += 1
            else:
                curr_ones += 1

            max_score = max(max_score, curr_zeros + total_ones - curr_ones)

        return max_score
