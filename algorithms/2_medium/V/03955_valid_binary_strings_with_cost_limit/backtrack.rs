impl Solution {
    fn backtrack(
        curr_len: i32,
        target_len: i32,
        curr_cost: i32,
        target_max_cost: i32,
        prev_is_one: bool,
        res: &mut Vec<String>,
        temp: &mut Vec<u8>,
    ) {
        if curr_cost > target_max_cost { return; }

        if curr_len == target_len {
            res.push(String::from_utf8(temp.clone()).unwrap());
            return;
        }

        temp.push(b'0');
        Self::backtrack(curr_len + 1, target_len, curr_cost, target_max_cost, false, res, temp);
        temp.pop();

        if !prev_is_one {
            temp.push(b'1');
            Self::backtrack(curr_len + 1, target_len, curr_cost + curr_len, target_max_cost, true, res, temp);
            temp.pop();
        }
    }

    pub fn generate_valid_strings(target_len: i32, target_max_cost: i32) -> Vec<String> {
        assert!(target_len >= 1 && target_len <= 12 && target_max_cost >= 0);
        let mut res: Vec<String> = Vec::new();
        let mut temp: Vec<u8> = Vec::with_capacity(target_len as usize);

        Self::backtrack(0, target_len, 0, target_max_cost, false, &mut res, &mut temp);

        res
    }
}
