impl Solution {
    pub fn compress(chars: &mut Vec<char>) -> i32 {

        let mut write_index = 0_usize;
        let mut read_index = 0_usize;
        let len = chars.len();

        while read_index < len {

            let mut curr_count = 1_i32;
            let curr_char = chars[read_index];

            while read_index < len - 1 && chars[read_index + 1] == chars[read_index] {
                curr_count += 1;
                read_index += 1;
            }

            chars[write_index] = curr_char;
            write_index += 1;

            if curr_count > 1 {

                let mut p = 1;
                while p <= curr_count {
                    p *= 10;
                }

                p /= 10;
                while p > 0 {
                    chars[write_index] = (((curr_count / p) % 10) as u8 +  b'0') as char;
                    write_index += 1;
                    p /= 10;
                }
            }

            read_index += 1;
        }

        write_index as i32
    }
}
