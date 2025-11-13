impl Solution {
    pub fn cal_points(operations: Vec<String>) -> i32 {
        let mut stack: Vec<i32> = Vec::new();

        for op in operations.iter() {
            if op == "+" {
                stack.push(stack[stack.len() - 1] + stack[stack.len() - 2]);
            } else if op == "D" {
                stack.push(2 * stack[stack.len() - 1]);
            } else if op == "C" {
                stack.pop();
            } else {
                stack.push(op.parse::<i32>().unwrap());
            }
        }

        stack.into_iter().sum()
    }
}
