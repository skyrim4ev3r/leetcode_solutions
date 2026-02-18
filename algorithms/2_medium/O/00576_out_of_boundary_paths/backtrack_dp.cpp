const array<array<int32_t, 2>, 4> DIRECTIONS{ array<int32_t, 2>{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
const int MOD_TO{ 1'000'000'007 };

class Solution {
    int backtrack(
        size_t i,
        size_t j,
        size_t move_left,
        size_t rows,
        size_t cols,
        vector<vector<vector<int32_t>>>& dp
    ) {
        if (i >= rows || j >= cols) {
            return 1;
        }

        if (move_left == 0) {
            return 0;
        }

        if (dp[i][j][move_left] != -1) {
            return dp[i][j][move_left];
        }

        int sum{ 0 };

        for (const auto& [dx, dy] : DIRECTIONS) {
            const size_t new_i{ static_cast<size_t>(static_cast<int32_t>(i) + dx) };
            const size_t new_j{ static_cast<size_t>(static_cast<int32_t>(j) + dy) };

            sum = (sum + backtrack(new_i, new_j, move_left - 1, rows, cols, dp)) % MOD_TO;
        }

        dp[i][j][move_left] = sum;
        return sum;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const size_t rows{ static_cast<size_t>(m) };
        const size_t cols{ static_cast<size_t>(n) };
        const size_t move_left{ static_cast<size_t>(maxMove) };
        const size_t i_start{ static_cast<size_t>(startRow) };
        const size_t j_start{ static_cast<size_t>(startColumn) };
        vector<vector<vector<int32_t>>> dp(rows, vector<vector<int32_t>>(cols, vector<int32_t>(move_left + 1, -1)));

        return backtrack(i_start, j_start, move_left, rows, cols, dp);
    }
};
