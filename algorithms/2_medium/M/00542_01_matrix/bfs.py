DIRECTIONS = [(1, 0), (-1, 0), (0, 1), (0, -1)]

class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        rows = len(mat)
        cols = len(mat[0])

        res = [[0] * cols for _ in range(rows)]
        is_visited = [[False] * cols for _ in range(rows)]
        q = deque()

        for i in range(rows):
            for j in range(cols):
                if mat[i][j] == 0:
                    q.append((i, j))
                    is_visited[i][j] = True

        curr_level = 0

        while q:
            curr_len = len(q)

            for _ in range(curr_len):
                (i, j) = q.popleft()
                res[i][j] = curr_level

                for (dx, dy) in DIRECTIONS:
                    new_i = i + dx
                    new_j = j + dy

                    if new_i >= rows or new_i < 0 or new_j >= cols or new_j < 0 or is_visited[new_i][new_j]:
                        continue

                    is_visited[new_i][new_j] = True
                    q.append((new_i, new_j))

            curr_level += 1

        return res
