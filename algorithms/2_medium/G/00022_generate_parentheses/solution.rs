impl Solution {
    fn generate_parenthesis_backtrack(res: &mut Vec<String>, stack: &mut Vec<u8>, n: i32, open_count: i32, close_count: i32) {
        if open_count == n && close_count == n {
            res.push(String::from_utf8(stack.clone()).unwrap());
            return;
        }

        if open_count < n {
            stack.push(b'(');
            Self::generate_parenthesis_backtrack(res, stack, n, open_count + 1, close_count);
            stack.pop();
        }

        if close_count < open_count {
            stack.push(b')');
            Self::generate_parenthesis_backtrack(res, stack, n, open_count, close_count + 1);
            stack.pop();
        }
    }

    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        let mut res: Vec<String> = Vec::new();
        let mut stack: Vec<u8> = Vec::with_capacity((n * 2) as usize);

        Self::generate_parenthesis_backtrack(&mut res, &mut stack, n, 0, 0);

        res
    }
}
