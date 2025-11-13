class Solution:
    def backtrack(self, res, tmp, candidates, candidates_len, target, curr_index):
        if target == 0:
            res.append(tmp[:])
            return

        for i in  range(curr_index, candidates_len):
            if target - candidates[i] >= 0:
                tmp.append(candidates[i])
                self.backtrack(res, tmp, candidates, candidates_len, target - candidates[i], i)
                tmp.pop()
            else:
                break

    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        tmp = []

        candidates.sort()
        self.backtrack(res, tmp, candidates, len(candidates), target, 0)

        return res
