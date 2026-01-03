impl Solution {
    const PRE_CALC_PRIMES: [i32; 25] = [
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
        31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
        73, 79, 83, 89, 97
    ];

    #[inline]
    fn is_prime(num: &i32) -> bool {
        let found = Self::PRE_CALC_PRIMES.binary_search(num);

        match found {
            Ok(_) => true,
            Err(_) => false,
        }
    }

    pub fn maximum_prime_difference(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        let mut left = 0_usize;
        let mut right = len - 1;

        while left < len && !Self::is_prime(&nums[left]) {
            left += 1;
        }

        while right < len && !Self::is_prime(&nums[right]) {
            right -= 1;
        }

        (right - left) as i32
    }
}
