class Solution:
    def uniquePathsWithObstacles(self, obstacle_grid: List[List[int]]) -> int:
        rows = len(obstacle_grid)
        cols = len(obstacle_grid[0])

        if obstacle_grid[0][0] == 1 or obstacle_grid[rows - 1][cols - 1] == 1:
            return 0

        dp = [[0] * cols for _ in range(rows)]
        dp[0][0] = 1

        for i in range(rows):
            for j in range(cols):
                if obstacle_grid[i][j] == 0:
                    if i > 0:
                        dp[i][j] += dp[i - 1][j]

                    if j > 0:
                        dp[i][j] += dp[i][j - 1]

        return dp[rows - 1][cols - 1]
