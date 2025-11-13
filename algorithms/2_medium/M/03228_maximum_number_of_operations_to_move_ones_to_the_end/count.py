class Solution:
    def maxOperations(self, s: str) -> int:
        s_len = len(s)
        op_count = 0
        count_ones = 0

        for i in range(s_len):
            if s[i] == '1':
                count_ones += 1
            elif i > 0  and s[i - 1] == '1':
                op_count += count_ones

        return op_count
