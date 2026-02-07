impl Solution {
    pub fn check_valid_string(s: String) -> bool {
        let mut points = 0_i32;
        let mut balance = 0_i32;

        for byte in s.as_bytes().iter() {
            if *byte == b')' {
                balance -= 1;

                if balance < 0 {
                    if points > 0 {
                        points -= 1;
                        balance += 1;
                    } else {
                        return false;
                    }
                }
            } else if *byte == b'(' {
                balance += 1;
            } else {
                points += 1;
            }
        }

        balance = 0;
        points = 0;

        for byte in s.as_bytes().iter().rev() {
            if *byte == b'(' {
                balance -= 1;

                if balance < 0 {
                    if points > 0 {
                        points -= 1;
                        balance += 1;
                    } else {
                        return false;
                    }
                }
            } else if *byte == b')' {
                balance += 1;
            } else {
                points += 1;
            }
        }

        true
    }
}
