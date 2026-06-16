typedef ptrdiff_t isize;

class Solution {
    static int calc_sum(const vector<int>& nums) {
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
        auto dp = vector<bool>(target + 1, false);
        dp[target] = true;

        for (isize i = len - 1; i >= 0; i -= 1) {
            const int num = nums[i];

            if (num > target) {
                // all nums are positive, so this num cant be use in any subsets
                return false;
            }

            for (isize j = 0; j <= target - num; j += 1) {
                dp[j] = dp[j] | dp[j + num];
            }

            if (dp[0]) {
                return true;
            }
        }

        return false;
    }
};
