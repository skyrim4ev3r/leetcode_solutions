impl Solution {
    #[inline]
    fn has_any_zero(mut n: i32) -> bool {
        while n > 0 {
            if n % 10 == 0 {
                return true;
            }

            n /= 10;
        }

        false
    }

    pub fn get_no_zero_integers(n: i32) -> Vec<i32> {
        for i in 1..n {
            if !Self::has_any_zero(i) && !Self::has_any_zero(n - i) {
                return vec![i, n - i];
            }
        }

        Vec::new()
    }
}
