class Solution {
    static int backtrack(
        vector<int>& memo,
        const vector<int>& nums,
        const int target
    ) {
        if (target == 0) { return 1; }
        if (target < 0) { return 0; }
        if (memo[target] != -1) { return memo[target]; }

        int res = 0;

        for (const auto num : nums) {
            res += backtrack(memo, nums, target - num);
        }

        memo[target] = res;
        return res;
    }

public:
    static int combinationSum4(const vector<int>& nums, int target) {
        assert(target > 0);
        auto memo = vector<int>(static_cast<size_t>(target) + 1, - 1);

        return backtrack(memo, nums, target);
    }
};
