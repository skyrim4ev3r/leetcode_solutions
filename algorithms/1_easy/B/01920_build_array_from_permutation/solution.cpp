class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        const size_t len{nums.size()};
        vector<int> res(len, 0);

        for (size_t i{0}; i < len; ++i) {
            res[i] = nums[static_cast<size_t>(nums[i])];
        }

        return res;
    }
};
