from heapq import heappush, heappop

class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        if grid[0][1] > 1 and grid[1][0] > 1:
            return -1

        DIRECTIONS = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        heap = []
        rows = len(grid)
        cols = len(grid[0])
        is_visited = [[False] * cols for _ in range(rows)]
        heappush(heap, (0, 0, 0))
        is_visited[0][0] = True

        while heap:
            old_cost, old_i, old_j = heappop(heap)

            for dx, dy in DIRECTIONS:
                new_i = old_i + dx
                new_j = old_j + dy

                if new_i >= rows or new_i < 0 or new_j >= cols or new_j < 0 or is_visited[new_i][new_j]:
                    continue

                grid_val = grid[new_i][new_j]
                new_cost = old_cost + 1 if old_cost + 1 >= grid_val else grid_val + ((grid_val - (old_cost + 1)) & 1)

                if new_i == rows - 1 and new_j == cols - 1:
                    return new_cost

                is_visited[new_i][new_j] = True
                heappush(heap, (new_cost, new_i, new_j))

        return -1
