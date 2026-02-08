impl Solution {
    const MAX_NUM: usize = 100;

    #[inline(always)]
    fn get_other_score(freqs: &[i32; Self::MAX_NUM + 1], other: i32) -> i32 {
        if other < 0 || other as usize > Self::MAX_NUM {
            0
        } else {
            freqs[other as usize]
        }
    }

    pub fn count_k_difference(nums: Vec<i32>, k: i32) -> i32 {
        let mut freqs = [0_i32; Self::MAX_NUM + 1];
        let mut count = 0_i32;

        for num in nums.into_iter() {
            count += Self::get_other_score(&freqs, num - k) + Self::get_other_score(&freqs, num + k);
            freqs[num as usize] += 1;
        }

        count
    }
}
