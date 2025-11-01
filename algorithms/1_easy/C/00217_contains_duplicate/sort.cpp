class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        const size_t len{nums.size()};
        sort(nums.begin(),nums.end());

        for (size_t i{1}; i < len; ++i) {
            if (nums[i - 1] == nums[i]) {
                return true;
            }
        }

        return false;
    }
};
