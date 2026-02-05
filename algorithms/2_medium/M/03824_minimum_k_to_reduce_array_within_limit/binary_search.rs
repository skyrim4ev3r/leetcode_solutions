impl Solution {
    pub fn minimum_k(nums: Vec<i32>) -> i32 {
        let mut low = 1_i32;
        let mut high = 10_000_i32;

        while low <= high {
            let mid = low + (high - low) / 2; 
            let op_needed = nums.iter().map(|&x| (x + mid - 1) / mid).sum::<i32>();

            if op_needed <= mid.pow(2) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        low
    }
}
