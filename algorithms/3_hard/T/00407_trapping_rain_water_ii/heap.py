class Solution:
    def trapRainWater(self, height_map: List[List[int]]) -> int:
        m = len(height_map)
        n = len(height_map[0])

        heap = []
        is_visited = [[False] * n for _ in range(m)]

        for i in range(m):
            for j in range(n):
                if i == 0 or i == m - 1 or j == 0 or j == n - 1:
                    is_visited[i][j] = True
                    heapq.heappush(heap, [height_map[i][j], i, j])

        total_sum = 0
        directions = [[-1, 0], [0, -1], [1,0], [0,1]]

        while heap:
            cell = heapq.heappop(heap)

            old_j = cell[2]
            old_i = cell[1]
            old_height = cell[0]

            for direction in directions:
                new_i = old_i + direction[0]
                new_j = old_j + direction[1]

                if new_i < 0 or new_i >= m or new_j < 0 or new_j >= n:
                    continue

                if is_visited[new_i][new_j]:
                    continue

                new_height = height_map[new_i][new_j]
                total_sum += max(0, old_height - new_height)
                is_visited[new_i][new_j] = True
                heapq.heappush(heap, [max(new_height, old_height), new_i, new_j])

        return total_sum
