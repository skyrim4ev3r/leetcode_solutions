impl Solution {
    pub fn range_bitwise_and(signed_left: i32, signed_right: i32) -> i32 {
        let mut shift = 0_u32;
        let mut left = signed_left as u32;
        let mut right = signed_right as u32;

        while right != left {
            shift += 1;
            right = right >> 1;
            left = left >> 1;
        }

        (right << shift) as i32
    }
}
