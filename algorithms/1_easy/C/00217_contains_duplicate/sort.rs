use std::collections::HashSet;
impl Solution {
    pub fn contains_duplicate(mut nums: Vec<i32>) -> bool {
        nums.sort_unstable();

        for window in nums.windows(2) {
            if window[0] == window[1] {
                return true;
            }
        }

        false
    }
}
