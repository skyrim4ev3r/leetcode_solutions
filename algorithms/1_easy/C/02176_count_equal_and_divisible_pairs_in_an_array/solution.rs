impl Solution {
    pub fn count_pairs(nums: Vec<i32>, k: i32) -> i32 {

        let k_usize = k as usize;
        let nums_len = nums.len();
        let mut count = 0;

        for i in 0..nums_len {
            for j in (i + 1)..nums_len {
                if nums[i] == nums[j] && (i * j) % k_usize == 0 {
                    count += 1;
                }
            }
        }

        count
    }
}
