class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        const size_t len{nums.size()};

        for (size_t i{1}; i < len; ++i) {
            nums[i] += nums[i - 1];
        }

        return nums;
    }
};
