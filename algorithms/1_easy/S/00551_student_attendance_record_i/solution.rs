impl Solution {
    pub fn check_record(s: String) -> bool {
        let mut absent_count = 0_i32;
        let mut consecutive_late_count = 0_i32;

        for byte in s.as_bytes().iter() {
            if *byte == b'A' {
                absent_count += 1;
                consecutive_late_count = 0;
            } else if *byte == b'L' {
                consecutive_late_count += 1;
            } else {
                consecutive_late_count = 0;
            }

            if consecutive_late_count == 3 || absent_count == 2 {
                return false;
            }
        }

        true
    }
}
