class Solution {
public:
    static int numberOfArithmeticSlices(vector<int>& nums) {
        const size_t len{ nums.size() };
        int prev_diff{ 0 };
        int curr_len{ 0 };
        int count{ 0 };

        for (size_t i{ 1 }; i < len; ++i) {
            if (nums[i] - nums[i - 1] == prev_diff) {
                curr_len += 1;
            } else {
                curr_len = 1;
            }

            count += curr_len - 1;
            prev_diff = nums[i] - nums[i - 1];
        }

        return count;
    }
};
