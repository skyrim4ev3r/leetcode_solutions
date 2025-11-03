class Solution {
public:
    int search(vector<int>& nums, int target) {
        size_t index{static_cast<size_t>(lower_bound(nums.begin(), nums.end(), target) - nums.begin())};

        if (index == nums.size() || nums[index] != target) {
            return -1;
        }

        return index;
    }
};
