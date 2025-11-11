class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        DIRECTIONS = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        n = len(grid)
        area = 0

        for i in range(n):
            for j in range(n):
                if grid[i][j] > 0:
                    area += 2; # for up and down area

                    for (dx, dy) in DIRECTIONS:
                        neighbor_i = i + dx
                        neighbor_j = j + dy

                        neighbor_h = 0 if neighbor_i >= n or neighbor_j >= n or \
                                          neighbor_i < 0 or neighbor_j < 0  else grid[neighbor_i][neighbor_j]
                        area += max(0, grid[i][j] - neighbor_h)

        return area
