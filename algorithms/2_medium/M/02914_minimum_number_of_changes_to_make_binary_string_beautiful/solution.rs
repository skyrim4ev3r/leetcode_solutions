impl Solution {
    pub fn min_changes(s: String) -> i32 {

        let s_bytes = s.into_bytes();
        let mut count = 0;
        let len = s_bytes.len();

        for index in (1..len).step_by(2) {
            if s_bytes[index] != s_bytes[index - 1] {
                count += 1;
            }
        }

        count
    }
}
