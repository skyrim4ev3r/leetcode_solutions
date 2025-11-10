class Solution:
    def balancedStringSplit(self, s: str) -> int:

        count = 0
        curr_diff = 0

        for ch in s:
            if ch == 'R':
                curr_diff += 1
            else:
                curr_diff -= 1

            if curr_diff == 0:
                count += 1

        return count
