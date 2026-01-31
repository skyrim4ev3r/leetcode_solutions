impl Solution {
    pub fn remove_duplicate_letters(s: String) -> String {
        let mut freqs = [0; 26];
        let mut used = [false; 26];
        let mut res: Vec<u8> = Vec::new();
        let bytes = s.as_bytes();

        for byte in bytes.iter() {
            freqs[(*byte - b'a') as usize] += 1;
        }

        for byte in bytes.iter() {
            let index = (*byte - b'a') as usize;
            freqs[index] -= 1;

            if !used[index] {
                while let Some(last_byte) = res.last() && *last_byte > *byte {
                    let index_last_byte = (*last_byte - b'a') as usize;

                    if freqs[index_last_byte] == 0 {
                        break;
                    }

                    used[index_last_byte] = false;
                    res.pop();
                }

                res.push(*byte);
                used[index] = true;
            }
        }

        String::from_utf8(res).unwrap()
    }
}
