// The API isBadVersion is defined for you.
// isBadVersion(version:i32)-> bool;
// to call it use self.isBadVersion(version)

impl Solution {
    pub fn first_bad_version(&self, n: i32) -> i32 {
        debug_assert!(n > 0);
		let mut lo = 1_i32;
        let mut hi = n;

        while lo <= hi {
            let mid = lo + (hi - lo) / 2;

            if self.isBadVersion(mid) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        lo
    }
}
