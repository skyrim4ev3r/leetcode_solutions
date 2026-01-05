impl Solution {
    pub fn minimum_sum(n: i32, k: i32) -> i32 {
        let half = k / 2;
        let cnt_l = n.min(half); // number of nums to select where num < k
        let cnt_r = 0_i32.max(n - half); // number of nums to select where num >= k

        let sum_l = (cnt_l * (cnt_l + 1)) / 2;
        let sum_r = cnt_r * (k - 1) + (cnt_r * (cnt_r + 1)) / 2;

        sum_l + sum_r
    }
}
