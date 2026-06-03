class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        n = len(cost)
        total_cost = 0

        cost.sort(reverse=True)

        for i in range(0, n, 3):
            total_cost += cost[i] + (cost[i + 1] if i + 1 < n else 0)

        return total_cost
