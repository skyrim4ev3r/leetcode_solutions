class Solution:
    def backtrack(
        self,
        curr_len,
        target_len,
        curr_cost,
        target_max_cost, 
        prev_is_one,
        res,
        temp,
    ):
        if curr_cost > target_max_cost: return

        if curr_len == target_len:
            res.append("".join(temp))
            return

        temp.append('0')
        self.backtrack(curr_len + 1, target_len, curr_cost, target_max_cost, False, res, temp)
        temp.pop()

        if not prev_is_one:
            temp.append('1')
            self.backtrack(curr_len + 1, target_len, curr_cost + curr_len, target_max_cost, True, res, temp)
            temp.pop()

    def generateValidStrings(self, target_len: int, target_max_cost: int) -> list[str]:
        assert(target_len >= 1 and target_len <= 12 and target_max_cost >= 0)
        res = []
        temp = []

        self.backtrack(0, target_len, 0, target_max_cost, False, res, temp)

        return res
