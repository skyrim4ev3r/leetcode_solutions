class Solution {
    static int binomial_coefficient(int n, int k) {
        if (k > n) { return 0; }
        if (k == 0 || k == n) { return 1; }
        int64_t res = 1;
        for (int i = 1; i <= k; ++i) {
            res = res * (n - k + i) / i;
        }
        return static_cast<int>(res);
    }

    static void backtrack(
        vector<vector<int>>& res,
        vector<int>& curr_vec,
        const int start_val,
        const int n,
        const int k
    ) {
        const int curr_vec_len = static_cast<int>(curr_vec.size());
        if (curr_vec_len == k) {
            res.push_back(curr_vec);
            return;
        }

        const int end_val = n - (k - curr_vec_len) + 1;
        for (int i = start_val; i <= end_val; ++i) {
            curr_vec.push_back(i);
            backtrack(res, curr_vec, i + 1, n, k);
            curr_vec.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        res.reserve(static_cast<size_t>(binomial_coefficient(n, k)));
        vector<int> curr_vec;
        curr_vec.reserve(static_cast<size_t>(k));
        backtrack(res, curr_vec, 1, n, k);

        return res;
    }
};
