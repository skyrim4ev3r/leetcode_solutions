impl Solution {
    pub fn count_majority_subarrays(nums: Vec<i32>, target: i32) -> i32 {
        let len = nums.len();
        let mut count = 0_i32;

        for i in 0..len {
            let mut freq = 0_usize;
            for j in i..len {
                if nums[j] == target {
                    freq += 1;
                }

                if freq > (j - i + 1) / 2 {
                    count += 1;
                }
            }
        }

        count
    }
}
