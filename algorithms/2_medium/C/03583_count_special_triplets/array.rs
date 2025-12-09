use std::collections::HashMap;

impl Solution {
    const MOD_TO: i64 = 1_000_000_007;

    pub fn special_triplets(nums: Vec<i32>) -> i32 {
        const NUM_MAX: i32 = 100_000;
        let mut freqs = [(0_i32, 0_i32); (NUM_MAX + 1) as usize];
        let mut count = 0_i64;

        for num in nums.iter() {
            freqs[*num as usize].1 += 1;
        }

        for &num in nums.iter() {
            freqs[num as usize].1 -= 1;

            let num_x2 = num + num;
            if num_x2 <= NUM_MAX {
                let pair_num_x2 = &freqs[num_x2 as usize];
                count = (count + (pair_num_x2.0 as i64) * (pair_num_x2.1 as i64)) % Self::MOD_TO;
            }

            freqs[num as usize].0 += 1;
        }

        count as i32
    }
}
