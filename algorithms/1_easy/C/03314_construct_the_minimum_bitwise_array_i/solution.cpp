class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        const size_t len{nums.size()};
        vector<int> res(len, -1);

        for (size_t i{0}; i < len; ++i) {
            for (int ans{nums[i] / 2}; ans < nums[i]; ++ans) {
                if ((ans | (ans + 1)) == nums[i]) {
                    res[i] = ans;
                    break;
                }
            }
        }

        return res;
    }
};
