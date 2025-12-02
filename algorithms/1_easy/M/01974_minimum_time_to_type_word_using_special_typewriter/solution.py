class Solution:
    def minTimeToType(self, word: str) -> int:
        circle_pos = 0
        cost = 0

        for ch in word:
            new_pos = ord(ch) - ord('a')
            curr_diff = abs(new_pos - circle_pos)

            min_cost = min(curr_diff, 26 - curr_diff)

            cost += min_cost + 1
            circle_pos = new_pos

        return cost
