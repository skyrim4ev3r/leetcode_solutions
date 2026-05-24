class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        size_t left = static_cast<size_t>(std::lower_bound(nums.begin(), nums.end(), target) - nums.begin());

        if (left == nums.size() || nums[left] != target) {
            return {-1, -1};
        }

        size_t right = static_cast<size_t>(std::upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1);

        return {static_cast<int>(left), static_cast<int>(right)};
    }
};
