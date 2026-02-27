class Solution:
    def maximumAmount(self, coins: List[List[int]]) -> int:
        rows = len(coins)
        cols = len(coins[0])
        skips = 3
        costs = [[[(-sys.maxsize - 1)] * skips for _ in range(cols + 1)] for _ in range(rows + 1)]
        costs[0][1] = [0] * skips

        for i in range(rows):
            for j in range(cols):
                for k in range(skips):
                    curr_cost = coins[i][j] + max(costs[i][j + 1][k], costs[i + 1][j][k])

                    if k > 0:
                        curr_cost = max(curr_cost, costs[i][j + 1][k - 1], costs[i + 1][j][k - 1])

                    costs[i + 1][j + 1][k] = curr_cost

        return max(costs[rows][cols])
