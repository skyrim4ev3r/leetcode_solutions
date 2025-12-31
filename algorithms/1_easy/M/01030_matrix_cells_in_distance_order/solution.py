class Solution:
    def allCellsDistOrder(self, rows: int, cols: int, r_center: int, c_center: int) -> List[List[int]]:
        def compare(x, r_center, c_center):
            return abs(x[0] - r_center) + abs(x[1] - c_center)
        res = []

        for i in range(rows):
            for j in range(cols):
                res.append([i , j])

        res.sort(key=lambda x: compare(x, r_center, c_center))

        return res
