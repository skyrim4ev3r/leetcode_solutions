use std::sync::Mutex;

static MAX_XOR_VALUE: usize = 2048;
static UNIQUE_XORS: Mutex<[bool; MAX_XOR_VALUE]> = {
    Mutex::new([false; MAX_XOR_VALUE])
};

impl Solution {
    const XOR_GROUP_SIZE: usize = 3; 

    #[inline(always)]
    fn calc_next_level(nums: &Vec<i32>, unique_xors: &mut [bool; MAX_XOR_VALUE]) {
        let mut prev_unique_xors = unique_xors.iter()
                                         .enumerate()
                                         .filter(|(_, flag)| **flag == true)
                                         .map(|(i, _)| i as i32)
                                         .collect::<Vec<i32>>();
        unique_xors.iter_mut().for_each(|flag| *flag = false);

        for &num in nums.iter() {
            for &prev_unique_xor in prev_unique_xors.iter() {
                unique_xors[(num ^ prev_unique_xor) as usize] = true;
            }
        }
    }

    pub fn unique_xor_triplets(nums: Vec<i32>) -> i32 {
        let mut unique_xors = UNIQUE_XORS.lock().unwrap();
        unique_xors.iter_mut().for_each(|flag| *flag = false);
        unique_xors[0] = true;

        for _ in 0..Self::XOR_GROUP_SIZE {
            Self::calc_next_level(&nums, &mut unique_xors);
        }

        unique_xors.iter().filter(|flag| **flag == true).count() as i32
    }
}
