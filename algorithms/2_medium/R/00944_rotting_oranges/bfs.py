DIRECTIONS = [(1, 0), (0, 1), (-1, 0), (0, -1)]
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        q = deque()

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 2:
                    q.append((i, j))

        count = 0

        while q:
            n = len(q)

            for _ in range(n):
                i, j = q.popleft()
                for dx, dy in DIRECTIONS:
                    new_i = i + dx
                    new_j = j + dy

                    if new_i >= rows or new_i < 0 or new_j >= cols or new_j < 0 or grid[new_i][new_j] != 1:
                        continue

                    grid[new_i][new_j] = 2
                    q.append((new_i, new_j))

            if q:
                count += 1

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    return -1

        return count
