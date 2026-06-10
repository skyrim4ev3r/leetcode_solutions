class Solution {
public:
    static int missingNumber(const vector<int>& nums) {
        const ptrdiff_t len = std::ssize(nums);
        assert(len > 0);
        int sum = 0;

        for (ptrdiff_t i = 0; i < len; i += 1) {
            sum += nums[i];
        }

        assert((len * (len + 1)) / 2 <= numeric_limits<int>::max());
        const int target_sum = static_cast<int>((len * (len + 1)) / 2);
        return target_sum - sum;
    }
};
