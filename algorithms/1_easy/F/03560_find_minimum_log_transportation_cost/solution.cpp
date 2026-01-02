class Solution {
    static inline long long min_cutting_cost_helper(long long n, long long m, long long k) {
        return max(0LL, m - k) * k + max(0LL, n - k) * k;
    }
public:
    static long long minCuttingCost(int n, int m, int k) {
        return min_cutting_cost_helper(
            static_cast<long long>(n),
            static_cast<long long>(m),
            static_cast<long long>(k)
        );
    }
};
