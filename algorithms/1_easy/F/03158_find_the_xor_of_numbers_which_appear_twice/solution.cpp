class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const size_t len{nums.size()};
        int res{0};

        for (size_t i{1}; i < len; ++i) {
            if (nums[i] == nums[i - 1]) {
                res ^= nums[i];
            }
        }

        return res;
    }
};
