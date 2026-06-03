impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        const INT_BITS: usize = i32::BITS as usize;
        let mut res = 0_u32;
        let mut freqs_bits = [0_u32; INT_BITS];

        for iter_num in nums.iter() {
            let num = (*iter_num) as u32;

            for i in 0..INT_BITS {
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

        res as i32
    }
}
