impl Solution {
    pub fn target_indices(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut smaller_count = 0_i32;
        let mut freq = 0_i32;

        for num in nums.into_iter() {
            if num < target {
                smaller_count += 1;
            } else if num == target {
                freq += 1;
            }
        }

        (smaller_count..smaller_count + freq).into_iter().collect::<Vec<_>>()
    }
}
