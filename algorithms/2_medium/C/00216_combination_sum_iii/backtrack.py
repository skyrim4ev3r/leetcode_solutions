class Solution:
    def backtrack(self, res, curr_vec, k, n, curr_sum, curr_num):

        if len(curr_vec) == k:
            if curr_sum == n:
                res.append(curr_vec[:])

            return

        for i in range(curr_num, 10):
            if i + curr_sum <= n:
                curr_vec.append(i)
                self.backtrack(res, curr_vec, k, n, curr_sum + i, i + 1)
                curr_vec.pop()


    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        res = []
        temp = []

        self.backtrack(res, temp, k, n, 0, 1)

        return res
