class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int sum {0};
        const size_t len{nums.size()};

        for (size_t i{0}; i < len; ++i) {
            if ((i & 1) == 0) {
                sum += nums[i];
            } else {
                sum -= nums[i];
            }
        }

        return sum;
    }
};
