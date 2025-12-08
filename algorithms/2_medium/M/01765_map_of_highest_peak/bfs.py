from collections import deque

DIRECTIONS = [(0, 1), (1, 0), (0, -1), (-1, 0)]

class Solution:
    def highestPeak(self, is_water: List[List[int]]) -> List[List[int]]:
        rows = len(is_water)
        cols = len(is_water[0])
        q = deque() 
        curr_height = 0

        for i in range(rows):
            for j in range(cols):
                if is_water[i][j] == 1:
                    q.append((i, j))

                is_water[i][j] -= 1

        while q:
            curr_len = len(q)
            curr_height += 1

            for _ in range(curr_len):
                i, j = q.popleft()

                for dx, dy in DIRECTIONS:
                    new_i = i + dx
                    new_j = j + dy

                    if new_i >= rows or new_i < 0 or new_j >= cols or new_j < 0 or is_water[new_i][new_j] != -1:
                        continue

                    is_water[new_i][new_j] = curr_height

                    q.append((new_i, new_j))

        return is_water
