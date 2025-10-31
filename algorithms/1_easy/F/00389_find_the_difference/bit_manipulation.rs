impl Solution {
    pub fn find_the_difference(s: String, t: String) -> char {

        let mut added_char = 0u8;

        s.into_bytes().into_iter().for_each(|byte| added_char ^= byte);
        t.into_bytes().into_iter().for_each(|byte| added_char ^= byte);

        added_char as char
    }
}
