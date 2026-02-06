class Solution {
public:
    int numTrees(int n) {
        const size_t n_usize{ static_cast<size_t>(n) };
        vector<int> dp(n_usize + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (size_t i{ 2 }; i <= n_usize; i += 1) {
            for (size_t j{ 1 }; j <= i; j += 1) {
                dp[i] += dp[i - j] * dp[j - 1];
            }
        }

        return dp[n_usize];
    }
};
