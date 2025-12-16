class Solution:
    def matrixScore(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        res = 0

        for i in range(m):
            if grid[i][0] == 0:
                for j in range(n):
                    grid[i][j] = 1 if grid[i][j] == 0 else 0

        for j in range(n):
            count_ones = 0

            for i in range(m):
                if grid[i][j] == 1:
                    count_ones +=1

            max_ones = max(count_ones, m - count_ones)
            curr_pow = n - 1 - j

            res += max_ones * pow(2, curr_pow)

        return res
