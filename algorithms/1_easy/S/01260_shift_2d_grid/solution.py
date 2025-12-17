class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m = len(grid)
        n = len(grid[0])
        shift_counts = k % (m * n)

        if shift_counts == 0:
            return grid

        res = [[0] * n for _ in range(m)]
        res_i = shift_counts // n
        res_j = shift_counts % n

        for i in range(m):
            for j in range(n):
                res[res_i][res_j] = grid[i][j]
                res_j += 1

                if res_j == n:
                    res_j = 0
                    res_i += 1

                    if res_i == m:
                        res_i = 0

        return res
