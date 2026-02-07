impl Solution {
    pub fn min_moves(nums: Vec<i32>) -> i32 {
        let min = *nums.iter().min().unwrap();
        let mut count = 0_i32;

        for num in nums.into_iter() {
            count += num - min;
        }

        count
    }
}
