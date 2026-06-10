#[derive(Clone, Copy)]
struct Entry {
    prev_idx: usize,
    val: i32,
    is_fill: bool,
}

impl Solution {
    pub fn contains_nearby_duplicate(nums: Vec<i32>, k: i32) -> bool {
        debug_assert!(nums.len() > 0 && k >= 0);
        let k = k as usize;
        let table_len = 2 * nums.len();
        let mut table = vec![ Entry{ prev_idx: 0, val: 0, is_fill: false}; table_len];

        for (i, &val) in nums.iter().enumerate() {
            let mut idx = val as usize % table_len;

            while table[idx].is_fill == true {
                if table[idx].val == val {
                    if i - table[idx].prev_idx <= k {
                        return true;
                    } else {
                        break;
                    }
                }
                idx = if idx + 1 == table_len { 0 } else { idx + 1 };
            }

            table[idx].prev_idx = i;
            table[idx].val = val;
            table[idx].is_fill = true;
        }

        false
    }
}
