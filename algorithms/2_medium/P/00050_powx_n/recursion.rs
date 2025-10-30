impl Solution {
    fn my_pow_helper(x: f64, n:i64) -> f64 {
        if n == 1 {
            return x;
        }

        let mut pow = Self::my_pow_helper(x, n / 2);

        pow *= pow;

        if (n & 1) == 1 {
            pow *= x;
        }

        pow
    }

    pub fn my_pow(x: f64, n: i32) -> f64 {
        if n == 0 {
            return 1_f64;
        }

        let n_i64 = n as i64;

        if n_i64 < 0 {
            return 1_f64 / Self::my_pow_helper(x, n_i64.abs());
        }

        Self::my_pow_helper(x, n_i64)
    }
}
