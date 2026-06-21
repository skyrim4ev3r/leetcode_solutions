impl Solution {
    pub fn max_sum_after_partitioning(arr: Vec<i32>, k: i32) -> i32 {
        assert!(k > 0);
        let k = k as usize;
        let len = arr.len();
        let mut dp = Vec::<i32>::with_capacity(len + 1);
        unsafe { dp.set_len(len + 1); }
        dp[len] = 0;

        for i in (0..len).rev() {
            let mut val = arr[i];
            let mut sum = val + dp[i + 1];
            for j in (i + 1)..(i + k).min(len) {
                val = val.max(arr[j]);
                let width = (j - i + 1) as i32;
                sum = sum.max(val * width + dp[j + 1]);
            }
            dp[i] = sum;
        }

        dp[0]
    }
}
