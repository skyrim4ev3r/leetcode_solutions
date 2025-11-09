class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) {
            return 0; // No range to consider
        }

        sort(nums.begin(), nums.end());

        const size_t len{nums.size()};
        size_t left{0};
        size_t right{static_cast<size_t>(k) - 1};
        int min_difference{std::numeric_limits<int>::max()}; // Initialize to maximum possible value

        while (right < len) {
            min_difference = min(min_difference, nums[right] - nums[left]);
            left += 1;
            right += 1;
        }

        return min_difference;
    }
};
