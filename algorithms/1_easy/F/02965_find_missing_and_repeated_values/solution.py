class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        n = len(grid)
        repeated = 0
        missed = 0

        for i in range(n):
            for j in range(n):
                val = abs(grid[i][j])
                other_i = ((val + n - 1) // n) - 1
                other_j = val % n

                if other_j == 0:
                    other_j = n - 1
                else:
                    other_j -= 1

                if grid[other_i][other_j] < 0:
                    repeated = abs(grid[i][j])
                else:
                    grid[other_i][other_j] *= -1

        for i in range(n):
            for j in range(n):
                if grid[i][j] > 0:
                    missed = i * n + (j + 1)
                    return [repeated, missed]

        return [-1, -1]
