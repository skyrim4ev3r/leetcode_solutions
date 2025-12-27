class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int sum {0};
        const size_t len {nums.size()};
        const size_t k_usize {static_cast<size_t>(k)};

        for (size_t i {0}; i < len; ++i) {
            if (
                (i < k_usize || nums[i - k_usize] < nums[i]) &&
                (i + k_usize >= len || nums[i + k_usize] < nums[i])
            ) {
                sum += nums[i];
            }
        }

        return sum;
    }
};
