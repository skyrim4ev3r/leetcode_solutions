class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum{nums[0]};
        int max{nums[0]};
        const size_t len{nums.size()};

        for (size_t i{1}; i < len; ++i) {
            if (nums[i - 1] < nums[i]) {
                sum += nums[i];
            } else {
                sum = nums[i];
            }

            max = std::max(max, sum);
        }

        return max;
    }
};
