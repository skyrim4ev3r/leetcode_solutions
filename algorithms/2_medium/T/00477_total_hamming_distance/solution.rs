impl Solution {
    const BITS_COUNT: usize = 32;

    pub fn total_hamming_distance(nums: Vec<i32>) -> i32 {
        let len_i32 = nums.len() as i32;
        let mut res = 0_i32;

        for shift in 0..Self::BITS_COUNT {
            let mask = 1 << shift;
            let count = nums.iter().filter(|x| (*x & mask) != 0).count() as i32;
            res += ((len_i32 - count) * count);
        }

        res
    }
}
