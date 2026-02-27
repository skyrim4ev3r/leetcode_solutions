const array<array<int, 2>, 4> DIRECTIONS{ array<int, 2>{1, 0}, {0, 1}, {-1, 0}, {0, -1} };

class Solution {
    static int dfs(
        const vector<vector<int>>& matrix,
        vector<vector<int>>& dp,
        const size_t i,
        const size_t j,
        const size_t rows,
        const size_t cols
    ) {
        const int cache{ dp[i][j] };
        if (cache != -1) {
            return cache;
        }

        int longest{ 1 };
        const int curr_cell{  matrix[i][j] };

        for (const auto& [dx, dy] : DIRECTIONS) {
            const size_t new_i{ static_cast<size_t>(static_cast<int>(i) + dx) };
            const size_t new_j{ static_cast<size_t>(static_cast<int>(j) + dy) };

            if (new_i >= rows || new_j >= cols || matrix[new_i][new_j] >= curr_cell) {
                continue;
            }

            longest = std::max(longest, 1 + dfs(matrix, dp, new_i, new_j, rows, cols));
        }

        dp[i][j] = longest;
        return longest;
    }
public:
    static int longestIncreasingPath(const vector<vector<int>>& matrix) {
        const size_t rows{ matrix.size() };
        const size_t cols{ matrix[0].size() };
        vector<vector<int>> dp(rows, vector<int>(cols, - 1));
        int max{ 0 };

        for (size_t i{ 0 }; i < rows; ++i) {
            for (size_t j{ 0 }; j < cols; ++j) {
                max = std::max(max, dfs(matrix, dp, i, j, rows, cols));
            }
        }

        return max;
    }
};
