class Solution:
    def sortMatrix(self, grid: List[List[int]]) -> List[List[int]]:

        n = len(grid)

        # Sort upper diagonals
        for pos in range(1, n):
            i = 0
            j = pos
            values = []

            while j < n:
                values.append(grid[i][j])
                j += 1
                i += 1

            values.sort()

            i = 0
            j = pos
            while j < n:
                grid[i][j] = values[i]
                i += 1
                j += 1

        # Sort lower diagonals
        for pos in range(0, n):
            i = pos
            j = 0
            values = []

            while i < n:
                values.append(grid[i][j])
                j += 1
                i += 1

            values.sort(reverse=True)

            i = pos
            j = 0
            while i < n:
                grid[i][j] = values[j]
                i += 1
                j += 1

        return grid
