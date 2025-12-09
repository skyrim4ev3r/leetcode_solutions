impl Solution {
    pub fn range_bitwise_and(mut left: i32, mut right: i32) -> i32 {
        let mut shift_count = 0_i32;

        while right != left {
            shift_count += 1;
            right = right >> 1;
            left = left >> 1;
        }

        right << shift_count
    }
}
