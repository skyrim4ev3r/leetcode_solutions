typedef ptrdiff_t isize;

class Solution {
public:
    static long long minOperations(const vector<int>& nums) {
        const isize len = std::ssize(nums);
        if (len <= 1) { return 0; }
        long long res = 0;

        for (isize i = 1; i < len; i += 1) {
            if (nums[i - 1] >= nums[i]) {
                res += nums[i - 1] - nums[i];
            }
        }

        return res;
    }
};
