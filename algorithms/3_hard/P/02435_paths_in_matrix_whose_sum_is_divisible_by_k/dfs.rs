impl Solution {
    const MOD_TO: i32 = 1_000_000_007;

    fn dfs(
        grid: &Vec<Vec<i32>>,
        dp: &mut Vec<Vec<Vec<i32>>>,
        m: usize,
        n: usize,
        k: i32,
        i: usize,
        j: usize,
        curr_mod: i32,
    ) -> i32 {
        if i >= m || j >= n {
            return 0;
        }

        let new_mod = (curr_mod + grid[i][j]) % k;

        if i == m - 1 && j == n - 1 {
            return if new_mod == 0 { 1 } else { 0 };
        }

        if dp[i][j][new_mod as usize] != - 1 {
            return dp[i][j][new_mod as usize];
        }

        let mut res = (Self::dfs(grid, dp, m, n, k, i + 1, j, new_mod) +
                        Self::dfs(grid, dp, m, n, k, i, j + 1, new_mod)) % Self::MOD_TO;

        dp[i][j][new_mod as usize] = res;
        res
    }

    pub fn number_of_paths(grid: Vec<Vec<i32>>, k: i32) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut dp = vec![vec![vec![-1_i32; k as usize]; n]; m];

        Self::dfs(&grid, &mut dp, m, n, k, 0_usize, 0_usize, 0_i32)
    }
}
