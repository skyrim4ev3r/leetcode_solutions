// The API isBadVersion is defined for you.
// isBadVersion(version:i32)-> bool;
// to call it use self.isBadVersion(version)

impl Solution {
    pub fn first_bad_version(&self, n: i32) -> i32 {
	
        let mut low = 1_i32;
        let mut high = n;

        while low <= high {
            let mid = low + (high - low) / 2;

            if self.isBadVersion(mid) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        low
    }
}
