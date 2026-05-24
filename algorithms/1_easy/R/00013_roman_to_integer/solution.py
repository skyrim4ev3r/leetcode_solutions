class Solution:
    def romanToInt(self, s: str) -> int:
        hashmap = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        total_sum = 0
        curr_max = 0

        for ch in reversed(s):
            val = hashmap[ch]
            if val >= curr_max:
                total_sum += val
                curr_max = val
            else:
                total_sum -= val

        return total_sum
