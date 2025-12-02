class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        rows = len(mat)
        cols = len(mat[0])
        temp = []

        for start_j in range(cols):
            i = 0
            j = start_j

            while i < rows and j < cols:
                temp.append(mat[i][j])
                i += 1
                j += 1

            temp.sort()

            i = 0
            j = start_j

            while i < rows and j < cols:
                mat[i][j] = temp[i]
                i += 1
                j += 1

            temp.clear()

        for start_i in range(rows):
            i = start_i
            j = 0

            while i < rows and j < cols:
                temp.append(mat[i][j])
                i += 1
                j += 1

            temp.sort()

            i = start_i
            j = 0

            while i < rows and j < cols:
                mat[i][j] = temp[j]
                i += 1
                j += 1

            temp.clear()

        return mat
