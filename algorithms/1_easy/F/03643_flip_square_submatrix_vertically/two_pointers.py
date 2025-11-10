class Solution:
    def reverseSubmatrix(self, grid: List[List[int]], x: int, y: int, k: int) -> List[List[int]]:
        for y_ofs in range(k):
            lower = x
            upper = x + k - 1
            curr_y = y + y_ofs

            while lower < upper:
                temp = grid[lower][curr_y]
                grid[lower][curr_y] = grid[upper][curr_y]
                grid[upper][curr_y] = temp

                lower += 1
                upper -= 1

        return grid
