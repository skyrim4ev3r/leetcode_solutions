impl Solution {
    pub fn max_length_between_equal_characters(s: String) -> i32 {
        let mut chars_pos: [(isize, isize); 26] = [(-1, -1); 26];
        let mut max_dis = -1_isize;

        for (i, byte) in s.as_bytes().iter().enumerate() {
            let chars_pos_index = (*byte - b'a') as usize;

            if chars_pos[chars_pos_index].0 == -1 {
                chars_pos[chars_pos_index].0 = i as isize;
            } else {
                chars_pos[chars_pos_index].1 = i as isize;
                max_dis = max_dis.max(chars_pos[chars_pos_index].1 - chars_pos[chars_pos_index].0 - 1);
            }
        }

        max_dis as i32
    }
}
