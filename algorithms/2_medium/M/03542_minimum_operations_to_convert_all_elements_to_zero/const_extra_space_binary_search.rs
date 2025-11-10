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
                let pos = nums[0..curr_stack_len].binary_search(&num).unwrap_or_else(|x| x);

                if pos == curr_stack_len {
                    nums[pos] = num;
                    curr_stack_len += 1;
                } else {
                    if nums[pos] == num {
                        count += (curr_stack_len - pos - 1) as i32;
                    } else {
                        nums[pos] = num;
                        count += (curr_stack_len - pos) as i32;
                    }

                    curr_stack_len = pos + 1;
                }
            }            
        }

        count + curr_stack_len as i32
    }
}
