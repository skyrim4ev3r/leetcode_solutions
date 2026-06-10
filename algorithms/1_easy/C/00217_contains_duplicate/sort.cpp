class Solution {
public:
    static bool containsDuplicate(vector<int>& nums) {
        const ptrdiff_t len = std::ssize(nums);
        sort(nums.begin(), nums.end());

        for (ptrdiff_t i = 1; i < len; i += 1) {
            if (nums[i - 1] == nums[i]) {
                return true;
            }
        }

        return false;
    }
};
