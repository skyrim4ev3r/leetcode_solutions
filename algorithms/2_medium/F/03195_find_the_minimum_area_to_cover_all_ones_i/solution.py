class Solution:
    def minimumArea(self, grid: List[List[int]]) -> int:
        max_i = 0
        min_i = sys.maxsize
        max_j = 0
        min_j = sys.maxsize
        found_one = False # Flag to check if any '1' is found

        rows = len(grid)
        cols = len(grid[0])

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    found_one = True

                    max_i = i # Directly assign since var "i" is always growing
                    min_i = min(min_i, i)

                    max_j = max(max_j, j)
                    min_j = min(min_j, j)

        if not found_one:
            return 0

        return (max_i - min_i + 1) * (max_j - min_j + 1)
