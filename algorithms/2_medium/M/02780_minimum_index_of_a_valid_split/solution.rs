impl Solution {
    #[inline]
    fn find_dominant(nums: &Vec<i32>) -> i32 {
        let mut curr_freq = 0_u32;
        let mut curr_num = 0_i32;

        for &num in nums.iter() {
            if curr_freq == 0 {
                curr_num = num;
                curr_freq = 1;
            } else {
                if num != curr_num {
                    curr_freq -= 1;
                } else {
                    curr_freq += 1;
                }
            }
        }

        curr_num
    }

    pub fn minimum_index(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        let dominant = Self::find_dominant(&nums);
        let mut right_count_dominant: usize = nums.iter().filter(|x| **x == dominant).count();
        let mut left_count_dominant = 0_usize;

        for (i, &num) in nums.iter().enumerate() {
            if num == dominant {
                right_count_dominant -= 1;
                left_count_dominant += 1;
            }

            if left_count_dominant > (i + 1) / 2 && right_count_dominant > (len - i - 1) / 2 {
                return i as i32;
            }
        }

        -1
    }
}
