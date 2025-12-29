class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        rows = len(land)
        cols = len(land[0])
        res = []

        for i_st in range(rows):
            for j_st in range(cols):
                if land[i_st][j_st] == 1:
                    i_en = i_st
                    j_en = j_st

                    while i_en + 1 < rows and land[i_en + 1][j_st] == 1:
                        i_en += 1

                    while j_en + 1 < cols and land[i_st][j_en + 1] == 1:
                        j_en += 1

                    for i in range(i_st, i_en + 1):
                        for j in range(j_st, j_en + 1):
                            land[i][j] = 0

                    res.append([i_st, j_st, i_en, j_en])

        return res
