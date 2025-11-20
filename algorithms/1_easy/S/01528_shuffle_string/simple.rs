// O(n) time, O(1) space
// Although there are nested loops, the structure of the swaps ensures that the overall time complexity is O(n).

impl Solution {
    pub fn restore_string(s: String, indices: Vec<i32>) -> String {
        let mut res = vec![0_u8; indices.len()];

        for (i, byte) in s.as_bytes().iter().enumerate() {
            res[indices[i] as usize] = *byte;
        }

        String::from_utf8(res).unwrap()
    }
}
