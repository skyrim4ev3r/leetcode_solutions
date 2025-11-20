class Solution {
public:
    int rob(vector<int>& nums) {
        const size_t len{nums.size()};

        if (len == 1) {
            return nums[0];
        }

        if (len == 2) {
            return std::max(nums[0], nums[1]);
        }

        nums[2] += nums[0];

        for (size_t i{3}; i < len; ++i) {
            nums[i] += std::max(nums[i - 2], nums[i - 3]);
        }

        return std::max(nums[len - 1], nums[len - 2]);
    }
};
