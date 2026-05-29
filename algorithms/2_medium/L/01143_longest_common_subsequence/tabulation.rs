impl Solution {
    pub fn longest_common_subsequence(text1: String, text2: String) -> i32 {
        let (b1, b2) = if text1.len() < text2.len() {
            (text2.as_bytes(), text1.as_bytes())
        } else {
            (text1.as_bytes(), text2.as_bytes())
        };

        let b1_len = b1.len();
        let b2_len = b2.len();
        let dp_cols = b2_len + 1;
        let mut dp = vec![0_i32; 2 * dp_cols];
        let mut curr = 0_usize;
        let mut prev = dp_cols;

        for i in (0..b1_len).rev() {
            for j in (0..b2_len).rev() {
                if b1[i] == b2[j] {
                    dp[curr + j] = 1 + dp[prev + j + 1];
                } else {
                    let right = dp[curr + j + 1];
                    let down = dp[prev + j];
                    dp[curr + j] = right.max(down);
                }
            }

            let temp = prev;
            prev = curr;
            curr = temp;
        }

        dp[prev]
    }
}