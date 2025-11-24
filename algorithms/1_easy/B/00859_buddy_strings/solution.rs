impl Solution {
    pub fn buddy_strings(s: String, goal: String) -> bool {
        if s.len() != goal.len() {
            return false;
        }

        let s_bytes = s.as_bytes();
        let goal_bytes = goal.as_bytes();
        let len = s_bytes.len();
        let mut diff: Vec<usize> = Vec::new();
        let mut freqs = [0_u16; 26];

        for i in 0..len {
            if s_bytes[i] != goal_bytes[i] {
                if diff.len() == 2 {
                    return false;
                }

                diff.push(i);
            }

            freqs[(s_bytes[i] - b'a') as usize] += 1;
        }

        if diff.len() == 2 {
            if s_bytes[diff[0]] == goal_bytes[diff[1]] && s_bytes[diff[1]] == goal_bytes[diff[0]] {
                return true;
            } else {
                return false;
            }
        }

        if diff.len() == 0 {
            for freq in freqs.iter() {
                if *freq > 1 {
                    return true;
                }
            }
        }

        false
    }
}
