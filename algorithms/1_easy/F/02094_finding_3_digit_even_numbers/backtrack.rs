impl Solution {
    fn backtrack(
        digits: &Vec<i32>,
        res: &mut Vec<i32>,
        is_seen: &mut Vec<bool>,
        len: usize,
        curr_num: i32,
        curr_depth: i32,
    ) {
        if curr_depth == 3 {
            if curr_num >= 100 && curr_num < 1000 && curr_num % 2 == 0 {
                res.push(curr_num);
            }

            return;
        }

        for i in 0..len {
            if !is_seen[i] {
                if i > 0 && digits[i] == digits[i - 1] && is_seen[i - 1] == false {
                    continue;
                }

                is_seen[i] = true;
                Self::backtrack(digits, res, is_seen, len, curr_num * 10 + digits[i], curr_depth + 1);
                is_seen[i] = false;
            }
        }
    }

    pub fn find_even_numbers(mut digits: Vec<i32>) -> Vec<i32> {
        digits.sort_unstable();

        let mut res: Vec<i32> = Vec::new();
        let len = digits.len();
        let mut is_seen = vec![false; len];

        Self::backtrack(&digits, &mut res, &mut is_seen, len, 0, 0);

        res
    }
}
