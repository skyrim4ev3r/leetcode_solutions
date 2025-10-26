from heapq import heappush, heappop

class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)

        if n <= 1:
            return 0

        is_visited =  [[False] * n for _ in range(n)]

        directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]

        heap = []

        heappush(heap, [grid[0][0], 0, 0])
        is_visited[0][0] = True

        while heap:
            cell = heappop(heap)

            for direction in directions:
                new_i = cell[1] + direction[0]
                new_j = cell[2] + direction[1]

                if new_i < 0 or new_i >= n or new_j < 0 or new_j >= n:
                    continue

                if is_visited[new_i][new_j]:
                    continue

                is_visited[new_i][new_j] = True

                new_cost = grid[new_i][new_j] if grid[new_i][new_j] > cell[0] else cell[0]

                if new_i == n - 1 and new_j == n - 1:
                    return new_cost

                heappush(heap,[new_cost, new_i, new_j])

        return -1
