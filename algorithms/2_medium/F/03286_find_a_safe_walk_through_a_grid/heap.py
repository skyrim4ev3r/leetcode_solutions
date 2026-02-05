from heapq import heappop, heappush

DIRECTIONS = [(1, 0), (0, 1), (-1, 0), (0, -1)]

class Solution:
    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:
        if health - grid[0][0] <= 0:
            return False

        rows = len(grid)
        cols = len(grid[0])
        heap = []
        visited = [[False] * cols for _ in range(rows)]
        visited[0][0] = True
        heappush(heap, (-(health - grid[0][0]), 0, 0))

        while heap:
            (prev_health_negative, i, j) = heappop(heap)
            prev_health = -prev_health_negative
            for (dx, dy) in DIRECTIONS:
                new_i = i + dx
                new_j = j + dy

                if new_i < 0 or new_j < 0 or new_i >= rows or new_j >= cols or visited[new_i][new_j]:
                    continue

                new_health = prev_health - grid[new_i][new_j]

                if new_i == rows - 1 and new_j == cols - 1:
                    return new_health > 0

                if new_health <= 0:
                    continue

                visited[new_i][new_j] = True
                heappush(heap, (-new_health, new_i, new_j))

        return False
