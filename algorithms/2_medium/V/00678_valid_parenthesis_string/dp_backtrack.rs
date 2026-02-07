impl Solution {
    fn backtrack(bytes: &[u8], dp: &mut Vec<Vec<bool>>, curr_index: usize, curr_balance: i32) -> bool {
        if curr_balance < 0 {
            return false;
        }

        if curr_index == bytes.len() {
            return curr_balance == 0;
        }

        if dp[curr_index][curr_balance as usize] == false {
            return false;
        }

        let res = {
            if bytes[curr_index] == b')' {
                Self::backtrack(bytes, dp, curr_index + 1, curr_balance - 1)
            } else if bytes[curr_index] == b'(' {
                Self::backtrack(bytes, dp, curr_index + 1, curr_balance + 1)
            } else {
                Self::backtrack(bytes, dp, curr_index + 1, curr_balance - 1) ||
                Self::backtrack(bytes, dp, curr_index + 1, curr_balance) ||
                Self::backtrack(bytes, dp, curr_index + 1, curr_balance + 1)
            }
        };

        dp[curr_index][curr_balance as usize] = res;
        res
    }

    pub fn check_valid_string(s: String) -> bool {
        let mut dp = vec![vec![true; s.len() + 1]; s.len() + 1];
        Self::backtrack(s.as_bytes(), &mut dp, 0, 0)
    }
}
