class Solution {
public:
    int minDifference(vector<int>& nums) {
        const size_t target_steps{ 3 };
        const size_t len{ nums.size() };

        if (len <= target_steps + 1) {
            return 0;
        }

        ranges::sort(nums);

        int min_diff{ numeric_limits<int>::max() };

        for (size_t i { 0 }; i <= target_steps; ++i) {
            const size_t j{ len - (target_steps - i) - 1 };
            min_diff = std::min(min_diff, nums[j] - nums[i]);
        }

        return min_diff;
    }
};
