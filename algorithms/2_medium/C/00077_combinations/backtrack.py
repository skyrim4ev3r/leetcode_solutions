class Solution:
    def backtrack(self, res, curr_vec, start_val, n, k):
        curr_vec_len = len(curr_vec)
        if curr_vec_len == k:
            res.append(curr_vec.copy())
            return

        end_val = n - (k - curr_vec_len) + 1
        for i in range(start_val, end_val + 1):
            curr_vec.append(i)
            self.backtrack(res, curr_vec, i + 1, n, k)
            curr_vec.pop()

    def combine(self, n: int, k: int) -> List[List[int]]:
        res = []
        curr_vec = []

        self.backtrack(res, curr_vec, 1, n, k)

        return res
