class Solution:
    def check_sub_mat(self, grid, i_st, j_st):
        seen = [False] * 10

        for i in range(i_st, i_st + 3):
            for j in range(j_st, j_st + 3):
                val = grid[i][j]

                if val < 1 or val > 9:
                    return False

                if seen[val]:
                    return False

                seen[val] = True

        first_col_sum = grid[i_st][j_st] + grid[i_st + 1][j_st] + grid[i_st + 2][j_st]

        for i in range(i_st, i_st + 3):
            if grid[i][j_st] + grid[i][j_st + 1] + grid[i][j_st + 2] != first_col_sum:
                return False

        for j in range(j_st + 1, j_st + 3):
            if grid[i_st][j] + grid[i_st + 1][j] + grid[i_st + 2][j] != first_col_sum:
                return False

        if (
            grid[i_st][j_st] + grid[i_st + 1][j_st + 1] + grid[i_st + 2][j_st + 2] != first_col_sum or
            grid[i_st + 2][j_st] + grid[i_st + 1][j_st + 1] + grid[i_st][j_st + 2] != first_col_sum
        ):
            return False

        return True

    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        count = 0

        if rows < 3 or cols < 3:
            return 0

        for i in range(rows - 2):
            for j in range(cols - 2):
                if self.check_sub_mat(grid, i, j):
                    count += 1
        return count
