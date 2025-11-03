class Solution:
    def largestAltitude(self, gain: List[int]) -> int:

        curr_sum = 0
        max_g = 0

        for g in gain:
            curr_sum += g
            max_g = max(max_g, curr_sum)

        return max_g
