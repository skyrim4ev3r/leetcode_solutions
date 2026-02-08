use std::collections::{HashSet, VecDeque};

impl Solution {
    pub fn open_lock(deadends: Vec<String>, target: String) -> i32 {
        let mut invalids = deadends.into_iter()
                                   .map(|x| x.into_bytes())
                                   .map(|x| [x[0], x[1], x[2], x[3]])
                                   .collect::<HashSet<_>>();
        let mut q: VecDeque<[u8; 4]> = VecDeque::new();
        let first_arr = [b'0', b'0', b'0', b'0'];
        let tc = target.into_bytes();
        let target_arr = [tc[0], tc[1], tc[2], tc[3]];

        if !invalids.insert(first_arr) {
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

                    if invalids.insert(temp.clone()) {
                        q.push_back(temp.clone());
                    }

                    temp[i] = if curr[i] == b'0' { b'9' } else { curr[i] - 1 };

                    if invalids.insert(temp.clone()) {
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
