class Solution:
    def reconstructMatrix(self, upper: int, lower: int, colsum: List[int]) -> List[List[int]]:
        if sum(colsum) != upper + lower:
            return []

        count_twos = colsum.count(2)

        if count_twos > upper or count_twos > lower:
            return []

        cols = len(colsum)
        rows = 2
        res = [[0] * cols for _ in range(rows)]
        remain_upper = upper - count_twos
        remian_lower = lower - count_twos

        for j in range(cols):
            match colsum[j]:
                case 1:
                    if remain_upper > 0:
                        res[0][j] = 1
                        remain_upper -= 1
                    else:
                        res[1][j] = 1
                        remian_lower -= 1
                case 2:
                    res[0][j] = 1
                    res[1][j] = 1

        return res
