impl Solution {
    pub fn halves_are_alike(s: String) -> bool {

        let s_bytes = s.into_bytes();
        let s_bytes_len = s_bytes.len();
        let half =  s_bytes_len / 2;
        let mut balance = 0_i32;

        for i in 0..s_bytes_len {
            match s_bytes[i] {
                b'a' | b'e' | b'i' | b'o' | b'u' | b'A' | b'E' | b'I' | b'O' | b'U' => {
                    if i < half {
                        balance += 1;
                    } else {
                        balance -= 1;
                    }
                },
                _ => {}
            }
        }

        balance == 0
    }
}
