impl Solution {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let len = nums.len();
        let split_point = len - (k as usize % len);

        nums[0..split_point].reverse();
        nums[split_point..len].reverse();
        nums.reverse();
    }
}
