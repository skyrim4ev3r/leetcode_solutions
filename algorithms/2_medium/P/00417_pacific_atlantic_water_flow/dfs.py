#
#   using two is_visited, one for atlantic ocean, one for pacific ocean
#
#   dfs every cells that are reachable from """atlantic ocean"""
#   dfs every cells that are reachable from """pacific ocean"""
#
#   at final every cells in grid with is_visited = true in "both is_visited" are reachable from both side,
#   and can add all of them to """result"""
#
#
#   using two is_visited, one for atlantic ocean, one for pacific ocean
#
#   dfs every cells that are reachable from """atlantic ocean"""
#   dfs every cells that are reachable from """pacific ocean"""
#
#   at final every cells in grid with is_visited = true in "both is_visited" are reachable from both side,
#   and can add all of them to """result"""
#

class Solution:
    def dfs(self, heights, is_visited, i, j):
        is_visited[i][j] = True

        for direction in self.directions:
            new_i = i + direction[0]
            new_j = j + direction[1]

            if new_i >= self.rows or new_i < 0 or new_j >= self.cols or new_j < 0:
                continue

            if is_visited[new_i][new_j] or heights[new_i][new_j] < heights[i][j]:
                continue

            self.dfs(heights, is_visited, new_i, new_j)

    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        self.rows = len(heights)
        self.cols = len(heights[0])

        pacific_is_visited = [[False] * self.cols for _ in range(self.rows)]
        atlantic_is_visited = [[False] * self.cols for _ in range(self.rows)]

        self.directions = [[0, -1], [0, 1], [1, 0], [-1, 0]]

        for i in range(self.rows):
            for j in range(self.cols):
                if i == 0 or j == 0:
                    self.dfs(heights, pacific_is_visited, i, j)

                if i == self.rows - 1 or j == self.cols - 1:
                    self.dfs(heights, atlantic_is_visited, i, j)

        res = []

        for i in range(self.rows):
            for j in range(self.cols):
                if atlantic_is_visited[i][j] and pacific_is_visited[i][j]:
                    res.append([i, j])

        return res
   
