class Solution {
public:
    int minCost(int n) {
        assert(n > 0 && n != numeric_limits<int>::max());
        if (n == 1) { return 0; }
        if (n == 2) { return 1; }

        auto dp = vector<int>(n + 1);
        dp[1] = 0;
        dp[2] = 1;

        for (int i = 3; i <= n; i += 1) {
            const int half = i / 2;
            const int other = i - half;
            dp[i] = (half * other) + dp[half] + dp[other];
        }

        return dp[n];
    }
};
