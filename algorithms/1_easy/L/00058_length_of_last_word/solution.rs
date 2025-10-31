impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {

        let mut count = 0_i32;
        let mut is_counting_started = false;
    
        for byte in s.into_bytes().into_iter().rev() {
            if byte != b' ' {
                is_counting_started = true;
            }

            if is_counting_started {
                if byte != b' ' {
                    count += 1;
                } else {
                    break;
                }
            }
        }

        count
    }
}
