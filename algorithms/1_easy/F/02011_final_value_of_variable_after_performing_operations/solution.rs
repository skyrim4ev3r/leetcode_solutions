impl Solution {
    pub fn final_value_after_operations(operations: Vec<String>) -> i32 {
        operations.into_iter().fold(0, | acc, op| if op.as_bytes()[1] == b'+' {acc + 1} else {acc - 1})
    }
}
