impl Solution {
    pub fn smallest_range_i(nums: Vec<i32>, k: i32) -> i32 {
        let mut min = i32::MAX;
        let mut max = i32::MIN;

        for num in nums.into_iter() {
            min = min.min(num);
            max = max.max(num);
        }

        ((max - min) - 2 * k).max(0)
    }
}
