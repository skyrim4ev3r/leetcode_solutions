use std::collections::HashMap;

impl Solution {
    #[inline]
    fn is_prime(num: &i32) -> bool {
        if *num == 2 {
            return true;
        }

        if *num <= 1 || *num % 2 == 0 {
            return false;
        }

        let sqrt_num = (*num as f64).sqrt() as i32;

        for i in (3..=sqrt_num).step_by(2) {
            if num % i == 0 {
                return false;
            }
        }

        true
    }

    pub fn check_prime_frequency(nums: Vec<i32>) -> bool {
        let mut freqs: HashMap<i32, i32> = HashMap::new();

        for num in nums.into_iter() {
            *freqs.entry(num).or_insert(0) += 1;
        }

        for (_, freq) in freqs.into_iter() {
            if Self::is_prime(&freq) {
                return true
            }
        }

        false
    }
}
