impl Solution {

    #[inline(always)]
    fn is_possible(nums: &Vec<i32>, divisor: i32, threshold: i32) -> bool {
        let mut sum = 0_i32;

        for &num in nums.iter() {
            sum += (num + divisor - 1) / divisor;

            if sum > threshold {
                return false;
            }
        }

        true
    }

    pub fn smallest_divisor(nums: Vec<i32>, threshold: i32) -> i32 {
        let mut low  = 1_i32;
        let mut high = nums.iter().max().map(|x| *x).unwrap() + 1;

        while low <= high {
            let mid = low + (high - low) / 2;

            if Self::is_possible(&nums, mid, threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        low
    }
}
