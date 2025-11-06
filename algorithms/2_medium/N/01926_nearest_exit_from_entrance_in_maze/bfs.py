DIRECTIONS = [(1, 0), (0, 1), (-1, 0), (0, -1)]

class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        cost_queue = deque()
        rows = len(maze)
        cols = len(maze[0])
        start_i = entrance[0]
        start_j = entrance[1]
        is_visited = [[False] * cols for _ in range(rows)]

        cost_queue.append((0, start_i, start_j))
        is_visited[start_i][start_j] = True

        while cost_queue:
            curr_cost, curr_i, curr_j = cost_queue.popleft()
            new_cost = curr_cost + 1
            for (dx, dy) in DIRECTIONS:
                new_i = curr_i + dx
                new_j = curr_j + dy

                if new_i < 0 or new_j < 0 or new_i >= rows or new_j >= cols or is_visited[new_i][new_j] or maze[new_i][new_j] == '+':
                    continue

                if new_i == rows - 1 or new_j == cols - 1 or new_i == 0 or new_j == 0:
                    return new_cost

                is_visited[new_i][new_j] = True
                cost_queue.append((new_cost, new_i, new_j))

        return -1
