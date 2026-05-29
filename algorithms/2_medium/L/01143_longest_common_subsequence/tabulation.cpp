class Solution {
public:
    static int longestCommonSubsequence(const string& text1, const string& text2) {
        const string& t1 = text1.size() < text2.size() ? text2 : text1;
        const string& t2 = text1.size() < text2.size() ? text1 : text2;

        const size_t t1_len = t1.size();
        const size_t t2_len = t2.size();
        const size_t dp_cols = t2_len + 1;
        auto dp = vector<int>(2 * dp_cols, 0);
        size_t curr = 0;
        size_t prev = dp_cols;

        for (auto i = static_cast<ptrdiff_t>(t1_len) - 1; i >= 0; i -= 1) {
            for (auto j = static_cast<ptrdiff_t>(t2_len) - 1; j >= 0; j -= 1) {
                if (t1[i] == t2[j]) {
                    dp[curr + j] = 1 + dp[prev + j + 1];
                } else {
                    const auto right = dp[curr + j + 1];
                    const auto down = dp[prev + j];
                    dp[curr + j] = std::max(right, down);
                }
            }

            const auto temp = prev;
            prev = curr;
            curr = temp;
        }

        return dp[prev];
    }
};