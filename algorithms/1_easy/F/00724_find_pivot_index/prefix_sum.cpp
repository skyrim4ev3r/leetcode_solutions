class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        const size_t len{nums.size()}; 
        int postfix_sum{0};
        int prefix_sum{0};

        for (const int &num: nums) {
            postfix_sum += num;
        }

        for (size_t i{0}; i < len; ++i) {
            if (i > 0) {
                prefix_sum += nums[i - 1];
            }

            postfix_sum -= nums[i];

            if (prefix_sum == postfix_sum) {
                return static_cast<int>(i);
            }
        }

        return -1;
    }
};
