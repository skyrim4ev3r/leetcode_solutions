class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int max{0};
        const size_t len{nums.size()};

        for (size_t i{0}; i < len; ++i) {
            for (size_t j{0}; j < len; ++j) {
                if (std::abs(nums[i] - nums[j]) <= std::min(nums[i], nums[j])) {
                    max = std::max(max, nums[i] ^ nums[j]);
                }
            }
        }

        return max;
    }
};
