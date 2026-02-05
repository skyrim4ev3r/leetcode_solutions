impl Solution {
    pub fn find_maximum_score(nums: Vec<i32>) -> i64 {
        let mut curr_max = 0_i64;
        let mut score = 0_i64;

        for num in nums.into_iter() {
            score += curr_max;
            curr_max = curr_max.max(num as i64);
        }

        score
    }
}
