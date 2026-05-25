class Solution {
    static inline size_t fact(size_t n) {
        size_t r = 1;
        for (size_t i = 2; i <= n; i += 1) {
            r *= i;
        }
        return r;
    }

    static void backtrack(
        vector<vector<int>>& res,
        const size_t rows,
        const size_t cols,
        vector<int>& temp,
        const size_t temp_index,
        vector<bool>& seen,
        const vector<int>& nums
    ) {
        if (temp_index == cols) {
            res.push_back(temp);
            return;
        }

        for (size_t idx = 0; idx < cols; idx += 1) {
            if (!seen[idx]) {
                seen[idx] = true;
                temp[temp_index] = nums[idx];
                backtrack(res, rows, cols, temp, temp_index + 1, seen, nums);
                seen[idx] = false;
            }
        }
    }
public:
    static vector<vector<int>> permute(const vector<int>& nums) {
        const size_t cols = nums.size();
        const size_t rows = fact(cols);
        vector<vector<int>> res;
        res.reserve(rows);
        vector<int> temp = vector<int>(cols, 0);
        vector<bool> seen = vector<bool>(cols, 0);
        backtrack(res, rows, cols, temp, 0, seen, nums);
        return res;
    }
};
