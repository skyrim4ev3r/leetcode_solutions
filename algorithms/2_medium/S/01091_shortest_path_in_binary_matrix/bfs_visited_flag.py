class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:       
        if grid[0][0] == 1:
            return -1

        rows = len(grid)
        cols = len(grid[0])

        if rows == 1 and cols == 1:
            return 1

        is_visited = [[False] * cols for _ in range(rows)]
        queue = deque()
        DIRECTIONS = [(1, -1), (1, 0), (1, 1), (0, 1), (0, -1), (-1, -1), (-1, 0), (-1, 1)]

        is_visited[0][0] = True
        queue.append((0, 0, 1))

        while queue:
            i, j, old_cost = queue.popleft()
            for (dx, dy) in DIRECTIONS:
                new_i = i + dx
                new_j = j + dy

                if new_i >= rows or new_j >= cols or new_i < 0 or new_j < 0:
                    continue

                if grid[new_i][new_j] == 1 or is_visited[new_i][new_j]:
                    continue

                if new_i == rows - 1 and new_j == cols - 1:
                    return old_cost + 1

                is_visited[new_i][new_j] = True
                queue.append((new_i, new_j, old_cost + 1))

        return -1
