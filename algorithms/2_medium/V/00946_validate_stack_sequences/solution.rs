impl Solution {
    pub fn validate_stack_sequences(pushed: Vec<i32>, popped: Vec<i32>) -> bool {                
        let popped_len = popped.len();
        let mut popped_index = 0_usize;
        let mut stack: Vec<i32> = Vec::with_capacity(popped_len);

        for val in pushed.iter() {
            stack.push(*val);

            while let Some(val) = stack.last() && *val == popped[popped_index] {
                stack.pop();
                popped_index += 1;

                if popped_index == popped_len {
                    return true;
                }
            }
        }

        false
    }
}
