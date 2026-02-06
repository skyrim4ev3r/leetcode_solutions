class Solution {
    int backtrack(int n, vector<int>& dp) {
        const int mem{ dp[static_cast<size_t>(n)] };
        if (mem != -1) {
            return mem;
        }

        int sum{ 0 };

        for (int i{ 1 }; i <= n; ++i) {
            sum += backtrack(n - i, dp) * backtrack(i - 1, dp);
        }

        dp[static_cast<size_t>(n)] = sum;
        return sum;
    }
public:
    int numTrees(int n) {
        vector<int> dp(static_cast<size_t>(n + 1), -1);
        dp[0] = 1;
        dp[1] = 1;

        return backtrack(n, dp);
    }
};
