impl Solution {
    pub fn h_index(citations: Vec<i32>) -> i32 {
        let len = citations.len();
        let mut left = 0_usize;
        let mut right = len - 1;
        let mut res = 0_i32;

        while left <= right && right < len {
            let mid = left + (right - left) / 2;
            let least_valid = (len - mid) as i32;

            if citations[mid] >= least_valid {
                res = least_valid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        res
    }
}
