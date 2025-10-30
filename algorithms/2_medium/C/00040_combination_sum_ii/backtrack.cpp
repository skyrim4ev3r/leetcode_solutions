class Solution {
    void backtrack(vector<vector<int>> &res, const vector<int> &candidates, vector<int> &curr_vec, size_t curr_pos, int target) {
        if (target == 0) {
            res.push_back(curr_vec);
            return;
        }

        size_t candidates_len{candidates.size()};

        if (curr_pos == candidates_len) {
            return;
        }

        for (size_t i{curr_pos}; i < candidates_len; ++i) {

            if (i != curr_pos && candidates[i] == candidates[i - 1]) {
                continue;
            } 

            if (target < candidates[i]) {
                break;
            }

            curr_vec.push_back(candidates[i]);
            backtrack(res, candidates, curr_vec, i + 1, target - candidates[i]);
            curr_vec.pop_back();           
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<int> curr_vec{};
        vector<vector<int>> res{};

        backtrack(res, candidates, curr_vec, 0, target);

        return res;
    }
};
