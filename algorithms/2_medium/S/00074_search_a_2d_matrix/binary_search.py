class Solution:
    def matrix_row_upper_bound(self, mat, target) -> int:
        rows = len(mat)
        low = 0
        high = rows - 1

        while low <= high and high < rows:
            mid = low + (high - low) // 2
            if mat[mid][0] > target:
                high = mid - 1
            else:
                low = mid + 1
        return high

    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        selected_row = self.matrix_row_upper_bound(matrix, target)
        if selected_row < 0:
            return False
        selected_col = bisect.bisect_left(matrix[selected_row], target)
        return selected_col < len(matrix[0]) and matrix[selected_row][selected_col] == target
