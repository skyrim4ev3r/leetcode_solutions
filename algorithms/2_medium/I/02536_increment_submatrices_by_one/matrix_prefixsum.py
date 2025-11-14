class Solution:
    def rangeAddQueries(self, n: int, queries: List[List[int]]) -> List[List[int]]:
        res = [[0] * n for _ in range(n)]

        for query in queries:
            i1 = query[0]
            j1 = query[1]
            i2 = query[2]
            j2 = query[3]

            for i in range(i1, i2 + 1):
                res[i][j1] += 1

                if j2 + 1 < n:
                    res[i][j2 + 1] -= 1

        for i in range(n):
            for j in range(1, n):
                res[i][j] += res[i][j - 1]

        return res
