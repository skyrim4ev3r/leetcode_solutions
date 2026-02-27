use std::collections::HashMap;

impl Solution {

    #[inline(always)]
    fn get_atom_end_index(bytes: &[u8], start: usize, len: usize) -> usize {
        let mut end = start + 1;
        while end < len && bytes[end] >= b'a' && bytes[end] <= b'z' {
            end += 1;
        }
        end
    }

    #[inline(always)]
    fn get_count_with_end_index(bytes: &[u8], start: usize, len: usize) -> (i32, usize) {
        if start >= len || !(bytes[start] >= b'0' && bytes[start] <= b'9') {
            return (1, start);
        }

        let mut count = 0_i32;
        let mut end = start;

        while end < len && bytes[end] >= b'0' && bytes[end] <= b'9' {
            count = count * 10 + (bytes[end] - b'0') as i32;
            end += 1;
        }

        (count, end)
    }

    pub fn count_of_atoms(formula: String) -> String {
        let bytes = formula.as_bytes();
        let len = bytes.len();
        let mut levels: Vec<HashMap<&[u8], i32>> = Vec::with_capacity(10);
        levels.push(HashMap::new());
        let mut i = 0_usize;

        while i < len {
            if bytes[i] >= b'A' && bytes[i] <= b'Z' {
                let atom_end_index = Self::get_atom_end_index(bytes, i, len);
                let (atom_count, final_end_index) = Self::get_count_with_end_index(bytes, atom_end_index, len);
                *levels.last_mut().unwrap().entry(&bytes[i..atom_end_index]).or_insert(0) += atom_count;
                i = final_end_index;
            } else if bytes[i] == b'(' {
                levels.push(HashMap::new());
                i += 1;
            } else if bytes[i] == b')' {
                let (multiplier, end_index) = Self::get_count_with_end_index(bytes, i + 1, len);
                let level_to_remove = levels.pop().unwrap();

                for (atom, atom_count) in level_to_remove {
                    *levels.last_mut().unwrap().entry(atom).or_insert(0) += (atom_count * multiplier);
                }

                i = end_index;
            } else {
                unreachable!("invalid input");
            }
        }

        let mut res_vec: Vec<String> = Vec::with_capacity(levels[0].len());

        for (atom, atom_count) in levels.pop().unwrap().into_iter() {
            let atom_str = String::from_utf8_lossy(atom).into_owned();

            if atom_count == 1 {
                res_vec.push(atom_str);
            } else {
                res_vec.push(format!("{}{}", atom_str, atom_count));
            }
        }

        res_vec.sort();
        res_vec.join("")
    }
}
