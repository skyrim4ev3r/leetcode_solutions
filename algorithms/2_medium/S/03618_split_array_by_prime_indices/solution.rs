impl Solution {
    #[inline]
    fn is_prime(n: usize) -> bool {
        if n == 2 || n == 3 || n == 5 {
            return true;
        }

        if n < 2 || n % 2 == 0 || n % 3 == 0 || n % 5 == 0 {
            return false;
        }

        let sqrt_n = (n as f64).sqrt() as usize;

        for i in (7..=sqrt_n).step_by(2) {
            if n % i == 0 {
                return false;
            }
        }

        true
    }

    pub fn split_array(nums: Vec<i32>) -> i64 {

        let mut sum = 0_i64;

        for i in 0..nums.len() {
            if Self::is_prime(i) {
                sum += nums[i] as i64;
            } else {
                sum -= nums[i] as i64;
            }
        }

        sum.abs()
    }
}
