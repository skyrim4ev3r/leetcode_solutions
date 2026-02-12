impl Solution {
    pub fn longest_palindrome(words: Vec<String>) -> i32 {
        let mut freqs = [[0_i32; 26]; 26];
        let mut max_len = 0_i32;

        for word in words.into_iter() {
            let bytes = word.as_bytes();
            let (i, j) = ((bytes[0] - b'a') as usize, (bytes[1] - b'a') as usize);
            let (complement_i, complement_j) = (j, i);

            if freqs[complement_i][complement_j] > 0 {
                // If complement_string exist then
                // Add both string & complement_string with total len of 4
                max_len += 4;
                freqs[complement_i][complement_j] -= 1;
            } else {
                freqs[i][j] += 1;
            }
        }

        // If self-palindrome strings are left,
        // Then we can use 1 of them as the middle part of final string.
        // Strings like: aa, bb, cc,..
        for i in 0..26 {
            if freqs[i][i] > 0 {
                max_len += 2;
                break;
            }
        }

        max_len
    }
}
