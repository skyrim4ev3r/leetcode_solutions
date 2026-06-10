impl Solution {
    pub fn add_digits(num: i32) -> i32 {
        debug_assert!(num >= 0);
        if num == 0 {
            return 0;
        }

        let res = num % 9;
        if res == 0 { 9 } else { res }
    }
}
