/*
    using flags for different cases, the name of flags are clear and does not need any more explanation
*/

impl Solution {
    pub fn is_number(s: String) -> bool {
        let (mut contains_e, mut contains_dot, mut contains_digits_before_e, mut contains_digits_after_e) = (false, false, false, false);
        let s_bytes = s.into_bytes();
        let len = s_bytes.len();

        for i in 0..len {
            if (s_bytes[i] >= b'A' && s_bytes[i] <= b'Z') || (s_bytes[i] >= b'a' && s_bytes[i] <= b'z') {
                if s_bytes[i] != b'e' as u8 && s_bytes[i] != b'E' {
                    return false;
                }
            }

            if s_bytes[i] == b'-' || s_bytes[i] == b'+' {
                if contains_e {
                    if s_bytes[i - 1] != b'e' && s_bytes[i - 1] != b'E' {
                        return false;
                    }
                } else {
                    if i != 0 {
                        return false;
                    }
                }
            }

            if s_bytes[i] == b'e' || s_bytes[i] == b'E' {
                if contains_e || !contains_digits_before_e {
                    return false;
                }

                contains_e = true;
            }

            if s_bytes[i] == b'.' {
                if(contains_e ||  contains_dot) {
                    return false;
                }

                contains_dot = true;
            }

            if s_bytes[i] >= b'0' && s_bytes[i] <= b'9' {
                if contains_e {
                    contains_digits_after_e = true;
                } else {
                    contains_digits_before_e = true;
                }
            }
        }

        if !contains_digits_before_e || (contains_e && !contains_digits_after_e) {
            return false;
        }

        true
    }
}
