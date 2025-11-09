class Solution:
    def construct2DArray(self, original: List[int], rows: int, cols: int) -> List[List[int]]:
        if rows * cols != len(original):
            return []

        res = []

        for i in range(rows):
            res.append(original[i * cols : (i + 1) * cols])

        return res
