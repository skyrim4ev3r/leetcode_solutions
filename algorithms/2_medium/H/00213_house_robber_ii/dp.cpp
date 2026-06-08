class Solution {
    static inline int rob_helper(const vector<int>& nums, const size_t start, const size_t end) {
        int prev_prev = 0;
        int prev = 0;
        int curr = 0;

        for (size_t i = start; i < end; i += 1) {
            assert(nums[i] >= 0);
            const int next = nums[i] + std::max(prev, prev_prev);
            prev_prev = prev;
            prev = curr;
            curr = next;
        }

        return std::max(curr, prev);
    }
public:
    static int rob(const vector<int>& nums) {
        const size_t len = nums.size();
        assert(len > 0);

        if (len == 1) {
            assert(nums[0] >= 0);
            return nums[0];
        }

        const int max_dp1 = rob_helper(nums, 0, len - 1);
        const int max_dp2 = rob_helper(nums, 1, len);

        return std::max(max_dp1, max_dp2);
    }
};
