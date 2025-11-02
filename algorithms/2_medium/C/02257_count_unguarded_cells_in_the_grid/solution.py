class Solution:
    def countUnguarded(self, rows: int, cols: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        grid = [['.'] * cols for _ in range(rows)]

        for i in range(len(guards)):
            grid[guards[i][0]][guards[i][1]] = 'g'

        for i in range(len(walls)):
            grid[walls[i][0]][walls[i][1]] = 'w'

        is_covered = False

        for j in range(cols):
            is_covered = False
            for i in range(rows):
                if grid[i][j] == 'g':
                    is_covered = True;
                elif grid[i][j] == 'w':
                    is_covered = False
                elif is_covered:
                    grid[i][j] = 'c'

            is_covered = False
            for i in range(rows - 1, -1, -1):
                if grid[i][j] == 'g':
                    is_covered = True;
                elif grid[i][j] == 'w':
                    is_covered = False
                elif is_covered:
                    grid[i][j] = 'c'

        for i in range(rows):
            is_covered = False
            for j in range(cols):
                if grid[i][j] == 'g':
                    is_covered = True;
                elif grid[i][j] == 'w':
                    is_covered = False
                elif is_covered:
                    grid[i][j] = 'c'

            is_covered = False
            for j in range(cols - 1, -1, -1):
                if grid[i][j] == 'g':
                    is_covered = True;
                elif grid[i][j] == 'w':
                    is_covered = False
                elif is_covered:
                    grid[i][j] = 'c'

        count = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == '.':
                    count += 1

        return count
