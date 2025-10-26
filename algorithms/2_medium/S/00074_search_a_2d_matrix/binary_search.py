class Solution(object):
    def searchMatrix(self, matrix, target):

        cols = len(matrix[0])

        for row in matrix:
            pos = bisect.bisect_left(row, target)
            if pos != cols and row[pos] == target:
                return True

        return False
