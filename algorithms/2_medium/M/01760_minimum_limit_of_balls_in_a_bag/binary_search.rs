impl Solution {
    pub fn minimum_size(nums: Vec<i32>, max_operations: i32) -> i32 {
        let mut high = nums.iter().map(|x| *x).max().unwrap();
        let mut low = 1_i32;

        while low <= high {
            let mid = low + (high - low) / 2;
            let mut op_left = max_operations;

            for &num in nums.iter() {
                if num > mid {
                    op_left = op_left - ((num + mid - 1) / mid) + 1;
                }

                if op_left < 0 {
                    break;
                }
            }

            match op_left.cmp(&0_i32) {
                std::cmp::Ordering::Less => low = mid + 1,
                _ => high = mid - 1,
            };
        }

        low
    }
}
