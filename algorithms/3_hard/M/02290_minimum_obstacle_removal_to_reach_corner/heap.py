from heapq import heappush, heappop

class Solution:
    def minimumObstacles(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        is_visited = [[False] * cols for _ in range(rows)]
        heap = []
        heappush(heap, (grid[0][0], 0, 0))
        is_visited[0][0] = True
        DIRECTIONS = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        while heap:
            old_cost, i, j = heappop(heap)
            for dx, dy in DIRECTIONS:
                new_i = i + dx
                new_j = j + dy

                if new_i >= rows or new_i < 0 or new_j >= cols or new_j < 0 or is_visited[new_i][new_j]:
                    continue

                new_cost = old_cost + grid[new_i][new_j]

                if new_i == rows - 1 and new_j == cols - 1:
                    return new_cost

                is_visited[new_i][new_j] = True
                heappush(heap, (new_cost, new_i, new_j))

        return -1
