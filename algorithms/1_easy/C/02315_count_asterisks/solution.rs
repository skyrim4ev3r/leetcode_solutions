impl Solution {
    pub fn count_asterisks(s: String) -> i32 {

        let mut s_bytes = s.into_bytes();
        let mut count = 0;
        let mut can_count = true;

        while let Some(byte) = s_bytes.pop() {
            match byte {
                b'|' => can_count = !can_count,
                b'*' => {
                    if can_count {
                        count += 1;
                    }
                },
                _ => {}
            }
        }

        count
    }
}
