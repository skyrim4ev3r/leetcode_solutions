class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        if num * 9 < sum:
            return ""

        res = ['0'] * num

        for i in range(num):
            if sum == 0:
                break

            curr_dig = min(sum, 9)
            sum -= curr_dig
            res[i] = chr(ord('0') + curr_dig)

        return "".join(res)
