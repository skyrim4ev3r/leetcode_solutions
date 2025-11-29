impl Solution {
    pub fn arithmetic_triplets(nums: Vec<i32>, diff: i32) -> i32 {
        let len = nums.len();
        let mut count = 0_i32;

        for i in 0..len {
            for j in (i + 1)..len {
                for k in (j + 1)..len {
                    if nums[k] - nums[j] == diff && nums[j] - nums[i] == diff {
                        count += 1;
                    }
                }
            }
        }

        count
    }
}
