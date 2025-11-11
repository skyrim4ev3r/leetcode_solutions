class Solution:
    def projectionArea(self, grid: List[List[int]]) -> int:
        n = len(grid)
        count_up_down = 0
        count_left_right = 0
        count_front_back = 0

        for i in range(n):
            max_left_right = 0

            for j in range(n):
                if grid[i][j] > 0:
                    count_up_down += 1

                max_left_right = max(max_left_right, grid[i][j])

            count_left_right += max_left_right

        for j in range(n):
            max_front_back = 0

            for i in range(n):
                max_front_back = max(max_front_back, grid[i][j])

            count_front_back += max_front_back

        return count_front_back + count_left_right + count_up_down
