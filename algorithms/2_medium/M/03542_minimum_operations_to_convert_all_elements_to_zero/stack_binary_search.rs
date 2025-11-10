impl Solution {
    pub fn min_operations(nums: Vec<i32>) -> i32 {
        let mut stack: Vec<i32> = Vec::with_capacity(nums.len());
        let mut count = 0_i32;

        for num in nums.into_iter() {
            if num == 0 {
                count += stack.len() as i32;
                stack.clear();
            } else {
                let stack_len = stack.len();
                let pos = stack.binary_search(&num).unwrap_or_else(|x| x);

                if pos == stack_len {
                    stack.push(num)
                } else {
                    if stack[pos] == num {
                        count += (stack_len - pos - 1) as i32;
                    } else {
                        stack[pos] = num;
                        count += (stack_len - pos) as i32;
                    }

                    stack.resize(pos + 1, 0);
                }
            }
        }

        count + stack.len() as i32
    }
}
