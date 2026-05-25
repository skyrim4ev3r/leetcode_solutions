impl Solution {
    fn pow_recursion(x: f64, n: i64) -> f64 {
        if n == 0 {
            return 1.0_f64;
        }

        let res = Self::pow_recursion(x, n / 2);

        if ((n & 1) == 1) {
            res * res * x
        } else {
            res * res
        }
    }

    pub fn my_pow(x: f64, n: i32) -> f64 {
        let pow_positive = (n as i64).abs();
        let res = Self::pow_recursion(x, pow_positive);
        
        if n < 0 { 1.0_f64 / res } else { res }
    }
}
