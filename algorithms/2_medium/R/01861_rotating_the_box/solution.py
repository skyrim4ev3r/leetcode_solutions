class Solution:
    def rotateTheBox(self, box_grid: List[List[str]]) -> List[List[str]]:
        original_rows = len(box_grid)
        original_cols = len(box_grid[0])

        rows = original_cols
        cols = original_rows

        res = [['.'] * cols for _ in range(rows)]
        for i in range(rows):
            for j in range(cols):
                res[i][j] = box_grid[cols - j - 1][i]

        for j in range(cols):

            top = 0
            bottom = 0

            while bottom < rows:

                leaf_count = 0
                while bottom < rows and res[bottom][j] != '*':
                    if res[bottom][j] == '#':
                        leaf_count += 1;
                        res[bottom][j] = '.'
                    bottom += 1

                for i in range((bottom - leaf_count),bottom):
                    res[i][j] = '#'

                bottom = bottom + 1
                top = bottom

        return res
