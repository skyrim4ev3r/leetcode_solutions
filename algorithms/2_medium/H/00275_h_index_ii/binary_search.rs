impl Solution {
    pub fn h_index(citations: Vec<i32>) -> i32 {
        let len = citations.len() as isize;
        debug_assert!(len > 0);
        let mut lo = 0_isize;
        let mut hi = len - 1;
        let mut res = 0_i32;

        while lo <= hi {
            let mid = lo + (hi - lo) / 2;
            let least_valid = (len - mid) as i32;

            if citations[mid as usize] >= least_valid {
                res = least_valid;
                hi = mid - 1;
            } else {
                lo = mid +1;
            }
        }

        res
    }
}
