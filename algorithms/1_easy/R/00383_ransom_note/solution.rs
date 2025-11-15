impl Solution {
    pub fn can_construct(ransom_note: String, magazine: String) -> bool {
        let mut freqs = [0_i32; 26];

        for byte in magazine.as_bytes().iter() {
            freqs[(*byte - b'a') as usize] += 1;
        }

        for byte in ransom_note.as_bytes().iter() {
            let index = (*byte - b'a') as usize;

            if freqs[index] == 0 {
                return false;
            }

            freqs[index] -= 1;
        }

        true
    }
}
