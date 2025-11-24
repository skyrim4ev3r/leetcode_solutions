class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        res = [1]
        n = rowIndex + 1

        while len(res) != n:
            curr_n = len(res)
            tmp = []

            for i in range(curr_n + 1):
                if i == 0:
                    tmp.append(res[0])
                elif i == curr_n:
                    tmp.append(res[i - 1])
                else:
                    tmp.append(res[i] + res[i - 1])

            res = tmp

        return res
