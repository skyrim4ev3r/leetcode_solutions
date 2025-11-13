class Solution {
    void backtrack(
        vector<vector<int>> &res,
        vector<int> temp,
        const vector<int>& candidates,
        const size_t candidates_len,
        const size_t start_index,
        const int target
    ) {
        if (target == 0) {
            res.push_back(temp);
            return;
        }

        for (size_t i{start_index}; i < candidates_len; ++i) {
            if (target - candidates[i] >= 0) {
                temp.push_back(candidates[i]);
                backtrack(res, temp, candidates, candidates_len, i, target - candidates[i]);
                temp.pop_back();
            } else {
                break;
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;

        sort(candidates.begin(), candidates.end());

        backtrack(res, temp, candidates, candidates.size(), 0, target);

        return res;
    }
};
