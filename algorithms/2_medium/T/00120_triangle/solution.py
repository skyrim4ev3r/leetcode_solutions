class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        rows = len(triangle)

        for curr_row in range(rows - 2, -1, -1):
            next_row = curr_row + 1
            curr_row_len = len(triangle[curr_row])

            for curr_col in range(curr_row_len):
                triangle[curr_row][curr_col] += min(triangle[next_row][curr_col], triangle[next_row][curr_col + 1])

        return triangle[0][0]
