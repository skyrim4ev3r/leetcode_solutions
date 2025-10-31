impl Solution {
    pub fn title_to_number(column_title: String) -> i32 {
        let (mut count, mut mul, mut ch_before_A, column_title_as_bytes) = (0i64, 1i64, 'A' as u8 - 1, column_title.as_bytes());
        for i in (0..column_title_as_bytes.len()).rev() {
            count += (column_title_as_bytes[i] - ch_before_A) as i64 * mul;
            mul *= 26;//using i64 to prevent overflow of this var in edge cases, without using extra condition
        }
        count as i32 //return the final count as i32, having used i64 to reduce casting during calculations
    }
}
