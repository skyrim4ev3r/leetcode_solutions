from heapq import heappush, heappop

DIRECTIONS = [(1, 0), (0, 1), (-1, 0), (0, -1)]

class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        rows = len(heights)
        cols = len(heights[0])
        costs = [[sys.maxsize] * cols for _ in range(rows)]
        heap = []
        heappush(heap, (0, 0, 0))

        while heap:
            (cost, i, j) = heappop(heap)

            if i == rows - 1 and j == cols - 1:
                return cost

            if cost > costs[i][j]:
                continue

            for (dx, dy) in DIRECTIONS:
                new_i = i + dx
                new_j = j + dy

                if new_i < 0 or new_j < 0 or new_i >= rows or new_j >= cols:
                    continue

                move_cost = abs(heights[i][j] - heights[new_i][new_j])
                new_cost = max(move_cost, cost)

                if new_cost >= costs[new_i][new_j]:
                    continue

                costs[new_i][new_j] = new_cost

                heappush(heap, (new_cost, new_i, new_j))

        return -1
