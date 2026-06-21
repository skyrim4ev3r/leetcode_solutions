typedef ptrdiff_t isize;

class Solution {
public:
    static int maxSumAfterPartitioning(const vector<int>& arr, int k_i32) {
        assert(k_i32 > 0);
        const isize k = k_i32;
        const isize len = std::ssize(arr);
        auto dp = vector<int>(len + 1);
        dp[len] = 0;

        for (isize i = len - 1; i >= 0; i -= 1) {
            int val = arr[i];
            int sum = val + dp[i + 1];
            const isize end_j = std::min(i + k, len);
            for (isize j = i + 1; j < end_j; j += 1) {
                val = std::max(val, arr[j]);
                const int width = static_cast<int>(j - i + 1);
                sum = std::max(sum, val * width + dp[j + 1]);
            }
            dp[i] = sum;
        }

        return dp[0];
    }
};
