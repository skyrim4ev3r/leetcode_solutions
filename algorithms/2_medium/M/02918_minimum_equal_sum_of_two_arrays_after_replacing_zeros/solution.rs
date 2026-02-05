impl Solution {
    #[inline(always)]
    fn calc_sum_and_zeros(nums: &Vec<i32>) -> (i64, i64) {
        let mut sum = 0_i64;
        let mut zeros = 0_i64;

        for &num in nums.iter() {
            sum += num as i64;

            if num == 0 {
                zeros += 1;
            }
        }

        (sum, zeros)
    }

    pub fn min_sum(nums1: Vec<i32>, nums2: Vec<i32>) -> i64 {
        let (sum1, zeros1) = Self::calc_sum_and_zeros(&nums1);
        let (sum2, zeros2) = Self::calc_sum_and_zeros(&nums2);
        let min_valid_sum1 = sum1 + zeros1;
        let min_valid_sum2 = sum2 + zeros2;

        if (zeros1 == 0 && sum1 < min_valid_sum2) || (zeros2 == 0 && min_valid_sum1 > sum2) {
            return -1;
        }

        min_valid_sum1.max(min_valid_sum2)
    }
}
