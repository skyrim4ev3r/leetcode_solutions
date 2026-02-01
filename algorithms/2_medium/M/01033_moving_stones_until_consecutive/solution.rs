impl Solution {
    pub fn num_moves_stones(a: i32, b: i32, c: i32) -> Vec<i32> {
        let mut nums = [a, b, c];
        nums.sort();

        let diff1 = nums[1] - nums[0] - 1;
        let diff2 = nums[2] - nums[1] - 1;

        let min_move = if diff1 == 0 && diff2 == 0 {0} else if diff1 > 1 && diff2 > 1 {2} else {1};
        let max_move = diff1 + diff2;

        vec![min_move, max_move]
    }
}
