impl Solution {
    pub fn find_max_length(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        let mut diff_to_len_vec: Vec<Option<i32>> = vec![None; (2 * len) + 1];
        let mut count_zeros = 0_usize;
        let mut count_ones = 0_usize;
        let mut longest = 0_i32;

        diff_to_len_vec[len] = Some(0);

        for (i, num) in nums.iter().enumerate() {
            match *num {
                1 => count_ones += 1,
                _ => count_zeros += 1,
            }

            let index = count_ones - count_zeros + len;
            if let Some(val) = diff_to_len_vec[index] {
                longest = longest.max(i as i32 + 1 - val);
            } else {
                diff_to_len_vec[index] = Some(i as i32 + 1);
            }            
        }

        longest
    }
}
