use std::collections::VecDeque;

impl Solution {

    #[inline(always)]
    fn calc_cost(max: i32, min: i32, right: usize, left: usize) -> i64 {
        ((right - left + 1) as i64) * ((max - min) as i64)
    }

    pub fn count_subarrays(nums: Vec<i32>, k: i64) -> i64 {
        let len = nums.len();
        let mut q_max: VecDeque<i32> = VecDeque::new();
        let mut q_min: VecDeque<i32> = VecDeque::new();
        let mut count = 0_i64;
        let mut left = 0_usize;

        for right in 0..len {
            let curr = nums[right];

            while let Some(val) = q_max.back() && *val < curr {
                q_max.pop_back();
            }

            while let Some(val) = q_min.back() && *val > curr {
                q_min.pop_back();
            }

            q_max.push_back(curr);
            q_min.push_back(curr);

            while  k < Self::calc_cost(q_max[0], q_min[0], right, left) {
                if nums[left] == q_max[0] {
                    q_max.pop_front();
                }

                if nums[left] == q_min[0] {
                    q_min.pop_front();
                }

                left += 1;
            }

            count += (right - left + 1) as i64;
        }

        count
    }
}
