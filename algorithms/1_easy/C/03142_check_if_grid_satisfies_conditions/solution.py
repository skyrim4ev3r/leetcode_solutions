class Solution:
    def satisfiesConditions(self, grid: List[List[int]]) -> bool:
        rows = len(grid)
        cols = len(grid[0])

        for j in range(cols):
            for i in range(rows):
                if (i > 0 and grid[i][j] != grid[i - 1][j]) or (j > 0 and grid[i][j] == grid[i][j - 1]):
                    return False

        return  True
