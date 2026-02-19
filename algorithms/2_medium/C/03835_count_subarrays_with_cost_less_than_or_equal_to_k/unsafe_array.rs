static mut Q_MAX: [i32; Solution::MAX_INPUT_SIZE] = [0; Solution::MAX_INPUT_SIZE];
static mut Q_MIN: [i32; Solution::MAX_INPUT_SIZE] = [0; Solution::MAX_INPUT_SIZE];

impl Solution {
    const MAX_INPUT_SIZE: usize = 100_000;

    #[inline(always)]
    fn calc_cost(max: i32, min: i32, right: usize, left: usize) -> i64 {
        ((right - left + 1) as i64) * ((max - min) as i64)
    }

    pub fn count_subarrays(nums: Vec<i32>, k: i64) -> i64 {
        let len = nums.len();
        let mut q_max_r = 0_usize;
        let mut q_max_l = 0_usize;
        let mut q_min_r = 0_usize;
        let mut q_min_l = 0_usize;
        let mut count = 0_i64;
        let mut left = 0_usize;

        for right in 0..len {
            let curr = nums[right];

            unsafe {
                while q_max_r > q_max_l && Q_MAX[q_max_r - 1] < curr {
                    q_max_r -= 1;
                }

                while q_min_r > q_min_l && Q_MIN[q_min_r - 1] > curr {
                    q_min_r -= 1;
                }

                Q_MIN[q_min_r] = curr;
                Q_MAX[q_max_r] = curr;
                q_min_r += 1;
                q_max_r += 1;

                while  k < Self::calc_cost(Q_MAX[q_max_l], Q_MIN[q_min_l], right, left) {
                    if nums[left] == Q_MAX[q_max_l] {
                        q_max_l += 1;
                    }

                    if nums[left] == Q_MIN[q_min_l] {
                        q_min_l += 1;
                    }

                    left += 1;
                }
            }

            count += (right - left + 1) as i64;
        }

        count
    }
}
