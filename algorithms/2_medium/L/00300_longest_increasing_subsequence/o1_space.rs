impl Solution {
    fn lower_bound(nums: &[i32], target: i32) -> usize {
        let mut start = 0_usize;
        let mut end = nums.len();

        while start < end {
            let mid = start + (end - start) / 2;

            if nums[mid] >= target {
                end = mid;
            } else {
                start = mid + 1;
            }
        }

        start
    }

    pub fn length_of_lis(mut nums: Vec<i32>) -> i32 {
        let len = nums.len();
        let mut stack_len = 0_usize;

        for i in 0..len {
            let curr_num = nums[i];
            let lb = Self::lower_bound(&nums[0..stack_len], curr_num);

            nums[lb] = curr_num;
            if lb == stack_len {
                stack_len += 1;
            }
        }

        stack_len as i32
    }
}
