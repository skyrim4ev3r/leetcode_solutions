impl Solution {
    pub fn repeated_substring_pattern(s: String) -> bool {

        let len = s.len();

        if len < 2 {
            return false;
        }
        
        let s_doubled = format!("{}{}", s, s);

        return s_doubled[1..2 * len - 1].contains(&s);
    }
}
