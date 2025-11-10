from heapq import heappush, heappop

class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        min_heap = []
        rows = len(grid)
        cols = len(grid[0])

        if rows == 1 and cols == 1:
            return grid[0][0]

        is_visited = [[False] * cols for _ in range(rows)]

        heappush(min_heap, [grid[0][0], 0, 0])
        is_visited[0][0] = True
        directions = [[0, 1], [1, 0]]
        while min_heap:
            cell = heappop(min_heap)
            for direction in directions:
                new_i = cell[1] + direction[0]
                new_j = cell[2] + direction[1]

                if new_j >= cols or new_i >= rows or is_visited[new_i][new_j]:
                    continue

                is_visited[new_i][new_j] = True
                new_val = grid[new_i][new_j] + cell[0]

                if new_i == rows - 1 and new_j == cols - 1:
                    return new_val

                heappush(min_heap, [new_val, new_i, new_j])

        return -1
