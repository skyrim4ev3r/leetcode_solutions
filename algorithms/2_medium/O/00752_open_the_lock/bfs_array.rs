use std::collections::{HashSet, VecDeque};

impl Solution {
    #[inline(always)]
    fn get_indices(bytes: &[u8]) -> (usize, usize, usize, usize) {
        (
            (bytes[0] - b'0') as usize,
            (bytes[1] - b'0') as usize,
            (bytes[2] - b'0') as usize,
            (bytes[3] - b'0') as usize,
        )
    }

    pub fn open_lock(deadends: Vec<String>, target: String) -> i32 {
        let mut invalids = [[[[false; 10]; 10]; 10]; 10];

        for d in deadends.into_iter() {
            let indices = Self::get_indices(d.as_bytes());
            invalids[indices.0][indices.1][indices.2][indices.3] = true;
        }

        let mut q: VecDeque<[u8; 4]> = VecDeque::new();
        let first_arr: [u8; 4] = [b'0', b'0', b'0', b'0'];
        let target_arr = {
            let tb = target.as_bytes();
            [tb[0], tb[1], tb[2], tb[3]]
        };

        if invalids[0][0][0][0] {
            return -1;
        }

        q.push_back(first_arr);
        let mut turns = 0_i32;

        while !q.is_empty() {
            let len = q.len();
            for _ in 0..len {
                let curr = q.pop_front().unwrap();

                if curr == target_arr {
                    return turns;
                }

                let mut temp = curr.clone();

                for i in 0..curr.len() {
                    temp[i] = if curr[i] == b'9' { b'0' } else { curr[i] + 1 };
                    let indices = Self::get_indices(&temp);

                    if !invalids[indices.0][indices.1][indices.2][indices.3] {
                        invalids[indices.0][indices.1][indices.2][indices.3] = true;
                        q.push_back(temp.clone());
                    }

                    temp[i] = if curr[i] == b'0' { b'9' } else { curr[i] - 1 };
                    let indices = Self::get_indices(&temp);

                    if !invalids[indices.0][indices.1][indices.2][indices.3] {
                        invalids[indices.0][indices.1][indices.2][indices.3] = true;
                        q.push_back(temp.clone());
                    }

                    temp[i] = curr[i];
                }
            }

            turns += 1;
        }

        -1
    }
}
