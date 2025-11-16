class Solution:
    def numSub(self, s: str) -> int:
        mod_to = 1_000_000_007
        total_count = 0
        curr_count = 0

        for ch in s:
            if ch == '1':
                curr_count += 1
            else:
                curr_count = 0

            total_count = (total_count + curr_count) % mod_to

        return total_count
