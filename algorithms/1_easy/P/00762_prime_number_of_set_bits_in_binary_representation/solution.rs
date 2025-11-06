impl Solution {
    #[inline]
    fn is_prime(num: u32) -> bool {
        match num {
            2 | 3 | 5 | 7 | 11 | 13 | 17 | 19 | 23 | 29 | 31 => true,
            _ => false
        }
    }

    pub fn count_prime_set_bits(left: i32, right: i32) -> i32 {
        let mut count = 0_i32;

        for num in left..=right {
            if Self::is_prime(num.count_ones()) {
                count += 1;
            }
        }

        count
    }
}
