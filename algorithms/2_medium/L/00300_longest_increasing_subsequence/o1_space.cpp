class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const ptrdiff_t len = std::ssize(nums);
        ptrdiff_t stack_len = 0;

        for (ptrdiff_t i = 0; i < len; i += 1) {
            const int curr_num = nums[static_cast<size_t>(i)];
            const ptrdiff_t lb = lower_bound(nums.begin(), nums.begin() + stack_len, curr_num) - nums.begin();

            nums[static_cast<size_t>(lb)] = curr_num;
            if (lb == stack_len) {
                stack_len += 1;
            }
        }

        return static_cast<int>(stack_len);
    }
};
