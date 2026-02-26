use std::collections::HashSet;

impl Solution {
    const XOR_GROUP_SIZE: usize = 3;

    #[inline(always)]
    fn calc_next_level(nums: &Vec<i32>, unique_xors: &mut HashSet<i32>) {
        let prev_unique_xors = unique_xors.iter().map(|x| *x).collect::<Vec<i32>>();
        *unique_xors = HashSet::new();

        for &num in nums.iter() {
            for &prev_unique_xor in prev_unique_xors.iter() {
                unique_xors.insert(num ^ prev_unique_xor);
            }
        }
    }

    pub fn unique_xor_triplets(nums: Vec<i32>) -> i32 {
        let mut unique_xors: HashSet<i32> = HashSet::new();
        unique_xors.insert(0);

        for _ in 0..Self::XOR_GROUP_SIZE {
            Self::calc_next_level(&nums, &mut unique_xors);
        }

        unique_xors.len() as i32
    }
}
