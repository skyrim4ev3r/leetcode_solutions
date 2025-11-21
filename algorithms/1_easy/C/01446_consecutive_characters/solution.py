class Solution:
    def maxPower(self, s: str) -> int:
        curr_power = 1
        max_power = 1
        n = len(s)

        for i in range(1, n):
            if s[i] == s[i - 1]:
                curr_power += 1
                max_power = max(max_power, curr_power)
            else:
                curr_power = 1

        return max_power
