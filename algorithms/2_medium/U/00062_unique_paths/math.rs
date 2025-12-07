impl Solution {
    pub fn unique_paths(m: i32, n: i32) -> i32 {
        let max = (if m > n {m - 1} else {n - 1}) as i64;
        let mut min = (if m < n {m - 1} else {n - 1}) as i64;
        let high = max + min;
        let mut sum = 1_i64;

        for k in (max + 1)..=high {
            sum *= k;

            while min > 1 && sum % min == 0 {
                sum /= min;
                min -= 1;
            }
        }

        sum as i32
    }
}
