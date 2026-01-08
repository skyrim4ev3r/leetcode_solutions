class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        const size_t rows {nums1.size()};
        const size_t cols {nums2.size()};
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        for (size_t i {rows - 1}; i < rows; --i) {
            for (size_t j {cols - 1}; j < cols; --j) {
                const int temp {nums1[i] * nums2[j]};

                if (i + 1 < rows && j + 1 < cols) {
                    const int d {dp[i + 1][j]};
                    const int r {dp[i][j + 1]};
                    const int rd {dp[i + 1][j + 1]};

                    dp[i][j] = max(temp, max(temp + rd, max(r, d)));
                } else if (i + 1 < rows) {
                    dp[i][j] = max(temp, dp[i + 1][j]);
                } else if (j + 1 < cols) {
                    dp[i][j] = max(temp, dp[i][j + 1]);
                } else {
                    dp[i][j] = temp;
                }
            }
        }

        return dp[0][0];
    }
};
