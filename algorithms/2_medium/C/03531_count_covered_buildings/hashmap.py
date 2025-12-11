class Solution:
    def countCoveredBuildings(self, n: int, buildings: List[List[int]]) -> int:
        rows_map = {}
        cols_map = {}
        count = 0

        for building in buildings:
            row_map = rows_map.get(building[0])
            if row_map == None:
                rows_map[building[0]] = [building[1], building[1]]
            else:
                row_map[0] = min(row_map[0], building[1])
                row_map[1] = max(row_map[1], building[1])

            col_map = cols_map.get(building[1])
            if col_map == None:
                cols_map[building[1]] = [building[0], building[0]]
            else:
                col_map[0] = min(col_map[0], building[0])
                col_map[1] = max(col_map[1], building[0])

        for building in buildings:
            i = building[0]
            j = building[1]

            if rows_map[i][0] < j and rows_map[i][1] > j and cols_map[j][0] < i and cols_map[j][1] > i:
                count += 1

        return count
