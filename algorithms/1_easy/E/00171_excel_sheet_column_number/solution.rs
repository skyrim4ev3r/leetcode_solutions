impl Solution {
    pub fn title_to_number(col_title: String) -> i32 {
        let mut count = 0_i32;

        for &byte in col_title.as_bytes() {
            count = count * 26 + (byte - (b'A' - 1)) as i32;
        }

        count
    }
}
