typedef ptrdiff_t isize;

class Solution {
    static bool dfs(
        const vector<int>& nums,
        const isize len,
        const isize curr_idx,
        const int curr_sum,
        const int target,
        vector<bool>& memo
    ) {
        if (curr_sum == target) {
            return true;
        }

        if (curr_sum > target || curr_idx >= len) {
            return false;
        }

        const isize memo_idx = curr_idx * target + curr_sum;

        if (!memo[memo_idx]) {
            return false;
        }

        const bool res = dfs(nums, len, curr_idx + 1, curr_sum + nums[curr_idx], target, memo) ||
                         dfs(nums, len, curr_idx + 1, curr_sum, target, memo);
        memo[memo_idx] = res;
        return res;
    }

    static inline int calc_sum(const vector<int>& nums) {
        int sum = 0;
        for (const int num : nums) {
            assert(num >= 0 && numeric_limits<int>::max() - sum >= num);
            sum += num;
        }
        return sum;
    }

public:
    static bool canPartition(const vector<int>& nums) {
        assert(std::ssize(nums) > 0);
        const int sum = calc_sum(nums);
        if ((sum & 1) == 1) {
            return false;
        }

        const int target = sum / 2;
        const isize len = std::ssize(nums);
        auto memo = vector<bool>(len * target, true);

        return dfs(nums, len, 0, 0, target, memo);
    }
};
