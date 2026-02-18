impl Solution {
    const INPUT_BITS: usize = 32;

    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut res = 0_i32;
        let mut freqs_bits = [0_i32; Self::INPUT_BITS];

        for num in nums.into_iter() {
            for i in 0..Self::INPUT_BITS {
                if (num & (1 << i)) != 0 {
                    freqs_bits[i] += 1;
                }
            }
        }

        for (i, freq) in freqs_bits.iter().enumerate() {
            if freq % 3 != 0 {
                res |= (1 << i);
            }
        }

        res
    }
}
