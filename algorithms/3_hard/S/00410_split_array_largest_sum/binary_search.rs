impl Solution {
    #[inline(always)]
    fn is_valid(nums: &[i32], max_valid_sum: i32, k: i32) -> bool {
        let mut curr_sum = 0_i32;
        let mut count = 0_i32;

        for &num in nums.iter() {
            if curr_sum + num <= max_valid_sum {
                curr_sum += num;
            } else {
                curr_sum = num;
                count += 1;

                if count == k {
                    return false;
                }
            }
        }

        true
    }

    pub fn split_array(nums: Vec<i32>, k: i32) -> i32 {
        let mut high = nums.iter().map(|x| *x).sum::<i32>();
        let mut low = *nums.iter().max().unwrap();

        while low <= high {
            let mid = low + (high - low) / 2;

            match Self::is_valid(&nums, mid, k) {
                true => high = mid - 1,
                false => low = mid + 1,
            }
        }

        low
    }
}
