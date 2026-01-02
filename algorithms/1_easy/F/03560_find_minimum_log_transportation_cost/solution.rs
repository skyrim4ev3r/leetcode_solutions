impl Solution {
    pub fn min_cutting_cost(n: i32, m: i32, k: i32) -> i64 {
        let (n, m, k) = (n as i64, m as i64, k as i64);
        0_i64.max(m - k) * k + 0_i64.max(n - k) * k
    }
}
