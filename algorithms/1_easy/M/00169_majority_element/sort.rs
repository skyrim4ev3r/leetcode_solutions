impl Solution {
    pub fn majority_element(mut nums: Vec<i32>) -> i32 {
        nums.sort_unstable();

        let len = nums.len();
        let mut max_freq = 0;
        let mut max_freq_num = 0;
        let mut curr_freq = 0;
        let mut curr_num = 0;

        for num in nums.into_iter() {
            if curr_num == num {
                curr_freq += 1;
            } else {
                curr_num = num;
                curr_freq = 1;
            }

            if curr_freq > max_freq {
                max_freq = curr_freq;
                max_freq_num = curr_num;
            }
        }

        return max_freq_num;
    }
}
