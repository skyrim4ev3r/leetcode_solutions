impl Solution {
    pub fn count_quadruplets(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut count = 0_i32;

        for d in (0..n).rev() {
            for c in (0..d).rev() {
                for b in (0..c).rev() {
                    for a in (0..b).rev() {
                        if nums[d] == nums[a] + nums[b] + nums[c] {
                            count += 1;
                        }
                    }
                }
            }
        }

        count
    }
}
