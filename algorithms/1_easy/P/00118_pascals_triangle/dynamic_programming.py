class Solution:
    def generate(self, numRows: int) -> List[List[int]]:

        res = []

        res.append([1])

        for i in range(1, numRows):
            tmp = []

            for j in range(i + 1):
                curr_val = 0

                if j < i:
                    curr_val += res[i - 1][j]

                if j > 0:
                    curr_val += res[i - 1][j - 1]

                tmp.append(curr_val)

            res.append(tmp)

        return res
