const int MOD_TO{1'000'000'007};

class Solution {
    static int dfs(
        const vector<vector<int>>& grid,
        vector<vector<vector<int>>>& dp,
        const size_t m,
        const size_t n,
        const int k,
        const size_t i,
        const size_t j,
        const int curr_mod
    ) {
        if (i >= m || j >= n) {
            return 0;
        }

        const int new_mod{(curr_mod + grid[i][j]) % k};

        if (i == m - 1 && j == n - 1) {
            return new_mod == 0 ? 1 : 0;
        }

        if (dp[i][j][static_cast<size_t>(new_mod)] != - 1) {
            return dp[i][j][static_cast<size_t>(new_mod)];
        }

        const int res = (dfs(grid, dp, m, n, k, i + 1, j, new_mod) +
                       dfs(grid, dp, m, n, k, i, j + 1, new_mod)) % MOD_TO;

        dp[i][j][static_cast<size_t>(new_mod)] = res;
        return res;
    }

public:
    static int numberOfPaths(vector<vector<int>>& grid, int k) {
        const size_t m{grid.size()};
        const size_t n{grid[0].size()};
        const size_t k_usize{static_cast<size_t>(k)};
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k_usize, - 1)));

        return dfs(grid, dp, m, n, k, 0, 0, 0);
    }
};
