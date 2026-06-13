impl Solution {
    pub fn count_numbers_with_unique_digits(n: i32) -> i32 {
        debug_assert!(n >= 0);
        let mut count = 1; // for n = 0
        let mut ways = 9;

        for i in 1..=n {
            count += ways;
            ways *= 0_i32.max(10 - i);
        }

        count
    }
}
