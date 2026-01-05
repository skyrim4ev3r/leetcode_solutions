impl Solution {
    pub fn max_sum(nums: Vec<i32>, k: i32) -> i32 {
        let mut freqs_bits = [0_i32; 32];
        const MOD_TO: i64 = 1_000_000_007;
        let mut res = 0_i64;

        for it in nums.iter() {
            let mut num = *it;
            let mut freqs_index = 0_usize;

            while num > 0 {
                if (num & 1) == 1 {
                    freqs_bits[freqs_index] += 1;
                }

                num = num >> 1;
                freqs_index += 1;
            }
        }

        let max_freq = *freqs_bits.iter().max().unwrap();
        let number_of_iter = max_freq.min(k);

        for _ in 0..number_of_iter {
            let mut curr = 0_i64;

            for freq in freqs_bits.iter_mut().rev() {
                curr = curr << 1;

                if *freq > 0 {
                    *freq -= 1;
                    curr |= 1;
                }
            }

            res = (res + curr * curr) % MOD_TO;
        }

        res as i32
    }
}
