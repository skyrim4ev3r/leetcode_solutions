impl Solution {
    pub fn max_dot_product(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let rows = nums1.len();
        let cols = nums2.len();
        let mut dp = vec![vec![0_i32; cols]; rows];

        for i  in (0..rows).rev() {
            for j in (0..cols).rev() {
                let temp = nums1[i] * nums2[j];

                if i + 1 < rows && j + 1 < cols {
                    let d = dp[i + 1][j];
                    let r = dp[i][j + 1];
                    let rd = dp[i + 1][j + 1];

                    dp[i][j] = temp.max(temp + rd).max(r).max(d);
                } else if (i + 1 < rows) {
                    dp[i][j] = temp.max(dp[i + 1][j]);
                } else if (j + 1 < cols) {
                    dp[i][j] = temp.max(dp[i][j + 1]);
                } else {
                    dp[i][j] = temp;
                }
            }
        }

        dp[0][0]
    }
}
