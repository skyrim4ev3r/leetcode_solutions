impl Solution {
    pub fn can_be_equal(s1: String, s2: String) -> bool {
        let (bytes1, bytes2) = (s1.as_bytes(), s2.as_bytes());
        let len = bytes1.len();
        let mut balance_freqs_even_indices = [0_i32; 26];
        let mut balance_freqs_odd_indices = [0_i32; 26];

        for i in 0..len {
            if (i & 1) == 0 {
                balance_freqs_even_indices[(bytes1[i] - b'a') as usize] += 1;
                balance_freqs_even_indices[(bytes2[i] - b'a') as usize] -= 1;
            } else {
                balance_freqs_odd_indices[(bytes1[i] - b'a') as usize] += 1;
                balance_freqs_odd_indices[(bytes2[i] - b'a') as usize] -= 1;
            }
        }

        for i in 0..26 {
            if balance_freqs_even_indices[i] != 0 || balance_freqs_odd_indices[i] != 0 {
                return false;
            }
        }

        true
    }
}
