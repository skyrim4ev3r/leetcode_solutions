impl Solution {
    pub fn second_highest(s: String) -> i32 {

        let mut is_seen = [false; 10];

        for byte in s.into_bytes() {
            if byte >= b'0' && byte <= b'9' {
                is_seen[(byte - b'0') as usize] = true;
            } 
        }

        let mut count = 0;

        for i in (0..=9).rev() {
            if is_seen[i] {
                count += 1;
                if count == 2 {
                    return i as i32;
                }
            }
        }

        -1
    }
}
