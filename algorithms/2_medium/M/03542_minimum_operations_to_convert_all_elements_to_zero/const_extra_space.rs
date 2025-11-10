impl Solution {
    pub fn min_operations(mut nums: Vec<i32>) -> i32 {
        let mut curr_stack_len = 0_usize;
        let mut count = 0_i32;
        let len = nums.len();

        for i in 0..len {
            let num = nums[i];

            if num == 0 {
                count += curr_stack_len as i32;
                curr_stack_len = 0;
            } else {
                while curr_stack_len > 0 && nums[curr_stack_len - 1] > num {
                    count += 1;
                    curr_stack_len -= 1;
                }

                if curr_stack_len > 0 && nums[curr_stack_len - 1] == num {
                    continue;
                }

                nums[curr_stack_len] = num;
                curr_stack_len += 1;
            }
        }

        count + curr_stack_len as i32
    }
}
