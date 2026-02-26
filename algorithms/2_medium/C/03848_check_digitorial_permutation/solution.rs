impl Solution {

    #[inline(always)]
    fn calc_sum_fact_digit(mut n: i32) -> i32 {
        let mut facts = [0_i32; 10];
        facts[0] = 1;
        for i in 1..10 {
            facts[i] = (i as i32) * facts[i - 1];
        }

        let mut sum = 0;

        while n > 0 {
            sum += facts[(n % 10) as usize];
            n /= 10;
        }

        sum
    }

    #[inline(always)]
    fn calac_freqs_digits(mut n: i32) -> [u8; 10] {
        let mut freqs = [0_u8; 10];
        while n > 0 {
            freqs[(n % 10) as usize] += 1;
            n /= 10;
        }
        freqs
    }

    pub fn is_digitorial_permutation(n: i32) -> bool {
        let sum_fact_digit = Self::calc_sum_fact_digit(n);

        Self::calac_freqs_digits(n) == Self::calac_freqs_digits(sum_fact_digit)
    }
}
