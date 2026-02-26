impl Solution {
    pub fn score_difference(nums: Vec<i32>) -> i32 {
        let mut points = [0_i32; 2];
        let mut curr_player = 0_usize;

        for (i, num) in nums.into_iter().enumerate() {
            if i % 6 == 5 {
                curr_player = (curr_player + 1) % 2;
            }

            if (num & 1) == 1 {
                curr_player = (curr_player + 1) % 2;
            }

            points[curr_player] += num;
        }

        points[0] - points[1]
    }
}
