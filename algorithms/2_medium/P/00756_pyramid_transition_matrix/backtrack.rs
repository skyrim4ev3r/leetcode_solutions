use std::collections::{HashMap, HashSet};

impl Solution {
    fn backtrack(
        map: &HashMap<Vec<u8>, Vec<u8>>,
        prev: &Vec<u8>,
        curr: &mut Vec<u8>,
        state: &mut bool,
        seen: &mut HashSet<Vec<u8>>
    ) {
        if *state || (prev.len() == 2 && curr.len() == 1) {
            *state = true;
            return;
        }

        if curr.len() == prev.len() - 1 {
            if !seen.insert(curr.clone()) {
                return;
            }

            let mut temp_new: Vec<u8> = Vec::with_capacity(curr.len() - 1);
            Self::backtrack(map, curr, &mut temp_new, state, seen);
            return;
        }

        let base = prev[curr.len()..curr.len() + 2].into_iter().map(|x| *x).collect::<Vec<u8>>();

        if let Some(vec) = map.get(&base) {
            for byte in vec.iter() {
                curr.push(*byte);
                Self::backtrack(map, prev, curr, state, seen);
                curr.pop();

                if *state {
                    return;
                }
            }
        }
    }

    #[inline]
    fn fill_transition_map(allowed: Vec<String>) -> HashMap<Vec<u8>, Vec<u8>> {
        let mut map: HashMap<Vec<u8>, Vec<u8>> = HashMap::new();
        for a in allowed.into_iter() {
            let mut bytes = a.into_bytes();
            let last_byte = bytes.pop().unwrap();
            map.entry(bytes).or_insert(Vec::new()).push(last_byte);
        }
        map
    }

    pub fn pyramid_transition(bottom: String, allowed: Vec<String>) -> bool {
        let map = Self::fill_transition_map(allowed);
        let mut seen: HashSet<Vec<u8>> = HashSet::new();
        let mut temp: Vec<u8> = Vec::with_capacity(bottom.len());
        let mut state = false;
        let bottom_bytes = bottom.into_bytes();

        Self::backtrack(&map, &bottom_bytes, &mut temp, &mut state, &mut seen);

        state
    }
}
