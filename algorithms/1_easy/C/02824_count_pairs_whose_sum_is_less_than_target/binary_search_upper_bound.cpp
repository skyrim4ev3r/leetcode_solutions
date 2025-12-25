class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        ranges::sort(nums, std::less<>());
        int count {0};
        const size_t len {nums.size()};

        for (size_t i{0}; i < len; ++i) {
            const int other_max {target - nums[i] - 1};
            const size_t pos {static_cast<size_t>(upper_bound(nums.begin(), nums.end(), other_max) - nums.begin())};   

            if (pos > i) {
                count += static_cast<int>(pos - i - 1);
            }
        }

        return count;
    }
};
