class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        const size_t len{nums.size()};

        for (size_t i{1}; i < len; ++i) {
            if (nums[i] % 2 == nums[i - 1] % 2) {
                return false;
            }
        }

        return true;
    }
};
