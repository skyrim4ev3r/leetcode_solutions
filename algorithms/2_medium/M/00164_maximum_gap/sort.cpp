class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int max{0};
        const size_t len{nums.size()};

        for (size_t i{1}; i < len; ++i) {
            max = std::max(max, nums[i] - nums[i - 1]);
        }

        return max;
    }
};
