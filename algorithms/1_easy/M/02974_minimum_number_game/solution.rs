impl Solution {
    pub fn number_game(mut nums: Vec<i32>) -> Vec<i32> {
        let len = nums.len();

        nums.sort_unstable();

        for i in (0..(len - 1)).step_by(2) {
            let tmp = nums[i + 1];
            nums[i + 1] = nums[i];
            nums[i] = tmp;
        }

        nums
    }
}
