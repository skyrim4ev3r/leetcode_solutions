class Solution:
    def minFlips(self, target: str) -> int:
        prev_ch = '0'
        count = 0
        for ch in target:
            if ch != prev_ch:
                prev_ch = ch
                count += 1

        return count
