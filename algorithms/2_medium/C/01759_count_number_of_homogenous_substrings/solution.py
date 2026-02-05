MOD_TO = 1_000_000_007

class Solution:
    def countHomogenous(self, s: str) -> int:
        prev_char = None
        total_count = 0
        contiguous_count = 0

        for ch in s:
            if ch == prev_char:
                contiguous_count += 1
            else:
                contiguous_count = 1
                prev_char = ch

            total_count = (total_count + contiguous_count) % MOD_TO

        return total_count
