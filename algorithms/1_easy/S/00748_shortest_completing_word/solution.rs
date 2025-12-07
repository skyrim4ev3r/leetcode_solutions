impl Solution {
    pub fn shortest_completing_word(license_plate: String, mut words: Vec<String>) -> String {
        let mut freqs_p = [0_i32; 26];
        let words_len = words.len();
        let mut curr_selected_index = words_len;

        for byte in license_plate.as_bytes().iter() {
            if *byte >= b'a' && *byte <= b'z' {
                freqs_p[(*byte - b'a') as usize] += 1;
            }

            if *byte >= b'A' && *byte <= b'Z' {
                freqs_p[(*byte - b'A') as usize] += 1;
            }
        }

        for i in 0..words_len {
            if curr_selected_index != words_len && words[curr_selected_index].len() <= words[i].len() {
                continue;
            }

            let mut freqs_w = [0_i32; 26];

            for byte in words[i].as_bytes().iter() {
                if *byte >= b'a' && *byte <= b'z' {
                    freqs_w[(*byte - b'a') as usize] += 1;
                }
            }

            let mut is_good = true;

            for j in 0..26 {
                if freqs_p[j] > freqs_w[j] {
                    is_good = false;
                    break;
                }
            }

            if is_good {
                curr_selected_index = i;
            }
        }

        words.swap_remove(curr_selected_index)
    }
}
