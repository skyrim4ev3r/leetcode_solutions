impl Solution {
    pub fn contains_duplicate(mut nums: Vec<i32>) -> bool {
        nums.sort_unstable();

        for w in nums.windows(2) {
            if w[0] == w[1] {
                return true;
            }
        }

        false
    }
}
