class Solution {
public:
    int maximumCount(vector<int>& nums) {
        const size_t lower_bound_zero {static_cast<size_t>(
            lower_bound(nums.begin(), nums.end(), 0) - nums.begin()
        )};

        const size_t upper_bound_zero {static_cast<size_t>(
            upper_bound(nums.begin(), nums.end(), 0) - nums.begin()
        )};

        const size_t len {nums.size()};

        return static_cast<int>(std::max(len - upper_bound_zero, lower_bound_zero));
    }
};
