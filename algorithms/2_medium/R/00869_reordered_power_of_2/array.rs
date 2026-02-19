impl Solution {
    const VALID_BITS_COUNT: usize = 31;

    #[inline(always)]
    fn get_digits_freqs(mut n: i32) -> [u8; 10] {
        let mut res = [0_u8; 10];

        while n > 0 {
            res[(n % 10) as usize] += 1;
            n /= 10;
        }

        res
    }

    pub fn reordered_power_of2(n: i32) -> bool {
        let digits_freqs_n = Self::get_digits_freqs(n);

        for i in 0..Self::VALID_BITS_COUNT {
            let digits_freqs_power_of_two = Self::get_digits_freqs(1 << i);

            if digits_freqs_n == digits_freqs_power_of_two {
                return true;
            }
        }

        false
    }
}
