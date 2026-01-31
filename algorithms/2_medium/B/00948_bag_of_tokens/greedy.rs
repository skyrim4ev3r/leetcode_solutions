impl Solution {
    pub fn bag_of_tokens_score(mut tokens: Vec<i32>, mut power: i32) -> i32 {
        if tokens.is_empty() {
            return 0;
        }

        let mut curr_score = 0_i32;
        let mut max_score = 0_i32;
        tokens.sort_unstable();
        let mut left = 0_usize;
        let mut right = tokens.len() - 1;

        while left <= right {
            if power >= tokens[left] {
                power -= tokens[left];
                curr_score += 1;
                max_score = max_score.max(curr_score);
                left += 1;
            } else if left < right && curr_score > 0 {
                power += tokens[right];
                curr_score -= 1;
                right -= 1;
            } else {
                break;
            }
        }

        max_score
    }
}
