class Solution:
    def backtrack(self, res, candidates, tmp_list, start_pos, target):
        if target == 0:
            res.append(tmp_list[:])
            return

        candidates_len = len(candidates)

        if start_pos == candidates_len:
            return

        for i in range(start_pos, candidates_len):

            if i != start_pos and candidates[i] == candidates[i - 1]:
                continue

            if target < candidates[i]:
                break

            tmp_list.append(candidates[i])
            self.backtrack(res, candidates, tmp_list, i + 1, target - candidates[i])
            tmp_list.pop()

    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:

        candidates.sort()

        res = []
        tmp_list = []

        self.backtrack(res, candidates, tmp_list, 0, target)

        return res
