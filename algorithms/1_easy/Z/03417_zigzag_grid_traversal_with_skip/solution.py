class Solution:
    def zigzagTraversal(self, grid: List[List[int]]) -> List[int]:
        rows = len(grid)
        cols = len(grid[0])
        total = rows * cols
        res = []

        for step in range(0, total, 2):
            i = step // cols
            j = step % cols if (i & 1) == 0 else cols - 1 -  (step % cols)
            res.append(grid[i][j])

        return res
