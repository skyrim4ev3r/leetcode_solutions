// O(n) time, O(1) space
// Although there are nested loops, the structure of the swaps ensures that the overall time complexity is O(n).

impl Solution {
    pub fn restore_string(s: String, mut indices: Vec<i32>) -> String {
        let mut bytes = s.into_bytes();
        let len = indices.len();

        for i in 0..len {
            let mut curr_index = indices[i] as usize;

            while curr_index != i {
                let temp_ch = bytes[i];
                bytes[i] = bytes[curr_index];
                bytes[curr_index] = temp_ch;

                let temp = indices[i];
                indices[i] = indices[curr_index];
                indices[curr_index] = temp;

                curr_index = indices[i] as usize;
            }
        }

        String::from_utf8(bytes).unwrap()
    }
}
