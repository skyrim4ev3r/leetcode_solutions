class Solution {
public:
    static int minOperations(vector<int>& nums) {
        size_t curr_stack_len{0};
        int count{0};

        for (const int &num: nums) {
            if (num == 0) {
                count += static_cast<int>(curr_stack_len);
                curr_stack_len = 0;
            } else {
                const size_t pos{static_cast<size_t>(lower_bound(nums.begin(), nums.begin() + curr_stack_len, num) - nums.begin())};

                if (pos == curr_stack_len) {
                    nums[pos] = num;
                    curr_stack_len += 1;
                } else {
                    if (nums[pos] == num) {
                        count += static_cast<int>(curr_stack_len - pos - 1);
                    } else {
                        nums[pos] = num;
                        count += static_cast<int>(curr_stack_len - pos);
                    }

                    curr_stack_len = pos + 1;
                }
            }
        }

        return count + static_cast<int>(curr_stack_len);
    }
};
