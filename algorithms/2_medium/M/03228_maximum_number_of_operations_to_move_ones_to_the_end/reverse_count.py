class Solution:
    def maxOperations(self, s: str) -> int:
        s_len = len(s)
        op_count = 0
        curr_shift_cost = 0

        for i in range(s_len - 1, -1, -1):
            if s[i] == '1':
                op_count += curr_shift_cost
            elif (i + 1 == s_len or s[i + 1] == '1'):
                curr_shift_cost += 1

        return op_count
