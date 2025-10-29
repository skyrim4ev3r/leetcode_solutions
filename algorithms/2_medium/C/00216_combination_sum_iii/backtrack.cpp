class Solution {
    void backtrack(vector<vector<int>> &res, vector<int> &curr_vec, size_t k, int n, int curr_sum, int curr_num) {

        if (curr_vec.size() == k) {
            if (curr_sum == n) {
                res.push_back(curr_vec);
            }

            return;
        }

        for (int i{curr_num}; i < 10; ++i) {
            if (i + curr_sum <= n) {
                curr_vec.push_back(i);
                backtrack(res, curr_vec, k, n, curr_sum + i, i + 1);
                curr_vec.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res{};
        vector<int> temp{};

        backtrack(res, temp, static_cast<size_t>(k), n, 0, 1);

        return res;
    }
};
