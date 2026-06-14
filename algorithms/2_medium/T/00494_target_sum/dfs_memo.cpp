typedef ptrdiff_t isize;

class Solution {
    static int dfs(
        const vector<int>& nums,
        const isize len,
        const isize curr_idx,
        const int curr_sum,
        const int target,
        const int sum_abs,
        vector<int>& memo,
        const isize memo_cols
    ) {
        if (curr_idx == len) {
            return curr_sum == target ? 1 : 0;
        }

        const isize memo_idx = (curr_idx * memo_cols) + (curr_sum + sum_abs);

        if (memo[memo_idx] != - 1) {
            return memo[memo_idx];
        }

        const int res = dfs(nums, len, curr_idx + 1, curr_sum + nums[curr_idx], target, sum_abs, memo, memo_cols) +
                        dfs(nums, len, curr_idx + 1, curr_sum - nums[curr_idx], target, sum_abs, memo, memo_cols);

        memo[memo_idx] = res;
        return res;
    }

    static int calac_sum_abs(const vector<int>& nums) {
        int sum = 0;
        for (const auto num : nums) {
            assert(numeric_limits<int>::max() - sum >= abs(num));
            sum += abs(num);
        }
        return sum;
    }
public:
    int findTargetSumWays(const vector<int>& nums, int target) {
        const isize len = std::ssize(nums);
        const int sum_abs = calac_sum_abs(nums);
        const isize memo_rows = len;
        const isize memo_cols = 1 + 2 * static_cast<isize>(sum_abs); // for all vals in range [-sum_abs, sum_abs]
        assert(numeric_limits<isize>::max() / memo_cols >= memo_rows);
        auto memo = vector<int>(memo_rows * memo_cols, -1);
        return dfs(nums, len, 0, 0, target, sum_abs, memo, memo_cols);
    }
};
