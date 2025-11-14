impl Solution {
    pub fn eval_rpn(tokens: Vec<String>) -> i32 {
        let mut stack: Vec<i32> = Vec::new();

        for token in tokens.iter() {
            if let Ok(num) = token.parse::<i32>() {
                stack.push(num);
            } else {
                let num2 = stack.pop().expect("Input is not valid: Not enough values in the stack");
                let num1 = stack.pop().expect("Input is not valid: Not enough values in the stack");

                match token.as_bytes()[0] {
                    b'+' => stack.push(num1 + num2),
                    b'-' => stack.push(num1 - num2),
                    b'*' => stack.push(num1 * num2),
                    b'/' => stack.push(num1 / num2),
                    _ => panic!("Input is not valid: Unexpected token '{}'", token),
                }
            }
        }

        stack.pop().expect("Input is not valid: Not enough values in the stack")
    }
}
