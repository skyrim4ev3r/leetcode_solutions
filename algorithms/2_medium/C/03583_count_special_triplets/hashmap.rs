use std::collections::HashMap;

impl Solution {
    const MOD_TO: i64 = 1_000_000_007;

    pub fn special_triplets(nums: Vec<i32>) -> i32 {
        let mut freqs: HashMap<i32, (i32, i32)> = HashMap::new();
        let mut count = 0_i64;

        for num in nums.iter() {
            freqs.entry(*num).or_insert((0, 0)).1 += 1;
        }

        for &num in nums.iter() {
            freqs.get_mut(&num).unwrap().1 -= 1;

            if let (Some(pair)) = (freqs.get(&(num * 2))) {
                count = (count + ((pair.0) as i64 * (pair.1) as i64)) % Self::MOD_TO;
            }

            freqs.get_mut(&num).unwrap().0 += 1;
        }

        count as i32
    }
}
