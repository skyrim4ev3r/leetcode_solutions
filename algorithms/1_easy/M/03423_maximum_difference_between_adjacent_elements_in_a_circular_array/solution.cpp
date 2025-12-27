class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        const size_t len {nums.size()};
        int max_diff {abs(nums[len - 1] - nums[0])};

        for (size_t i {0}; i + 1 < len; ++i) {
            max_diff = max(max_diff, abs(nums[i + 1] - nums[i]));
        }

        return max_diff;
    }
};
