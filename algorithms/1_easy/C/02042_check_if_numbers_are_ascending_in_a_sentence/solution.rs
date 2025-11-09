impl Solution {
    pub fn are_numbers_ascending(s: String) -> bool {
        let mut curr_max = i32::MIN;

        for part in s.split_whitespace() {
            if let Ok(num) = part.parse::<i32>() {
                if num <= curr_max {
                    return false;
                }

                curr_max = num;
            }
        }

        true
    }
}
