impl Solution {
    pub fn sum_of_good_integers(n: i32, k: i32) -> i32 {
        let mut sum = 0_i32;

        for x in (n - k).max(1)..=(n + k) {
            if (x & n) == 0 {
                sum += x;
            }
        }

        sum
    }
}
