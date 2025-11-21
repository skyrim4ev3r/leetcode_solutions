use std::collections::HashSet;

impl Solution {
    pub fn is_path_crossing(path: String) -> bool {
        let mut visited: HashSet<(i16, i16)> = HashSet::new();
        visited.insert((0, 0));
        let mut i = 0_i16;
        let mut j = 0_i16;

        for byte in path.as_bytes().iter() {
            match *byte {
                b'N' => i -= 1,
                b'S' => i += 1,
                b'E' => j += 1,
                b'W' => j -= 1,
                _ => {},
            }

            if !visited.insert((i, j)) {
                return true;
            }
        }

        false
    }
}
