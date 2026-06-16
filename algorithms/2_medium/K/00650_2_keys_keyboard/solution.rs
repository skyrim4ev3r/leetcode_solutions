impl Solution {
    fn largest_proper_divisor(n: i32) -> i32 {
        for i in 2..=n.isqrt() {
            if n % i == 0 {
                return n / i;
            }
        }
        1
    }

    pub fn min_steps(mut n: i32) -> i32 {
        debug_assert!(n > 0);
        let mut cnt = 0_i32;

        while n > 1 {
            let lpd = Self::largest_proper_divisor(n);
            cnt += n / lpd;
            n = lpd;
        }

        cnt
    }
}
