class Solution:
    def minCost(self, s: str, cost: List[int]) -> int:
        n = len(s)
        cost_chars = [0] * 26
        total_cost = 0

        for i in range(n):
            cost_chars[ord(s[i]) - ord('a')] += cost[i]
            total_cost += cost[i]

        max_cost_char = 0

        for cost_char in cost_chars:
            max_cost_char = max(max_cost_char, cost_char)

        return total_cost - max_cost_char
