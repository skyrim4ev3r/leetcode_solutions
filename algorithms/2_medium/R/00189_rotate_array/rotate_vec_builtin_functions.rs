impl Solution {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let k_usize = (k as usize) % nums.len();
        nums.rotate_right(k_usize);
    }
}
