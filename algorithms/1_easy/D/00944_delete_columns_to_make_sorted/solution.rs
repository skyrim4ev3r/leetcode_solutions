impl Solution {
    pub fn min_deletion_size(strs: Vec<String>) -> i32 {
        let rows = strs.len();
        let cols = strs[0].len();
        let mut count = 0;

        for j in 0..cols {
            let mut is_sorted = true;

            for i in 1..rows {
                if strs[i].as_bytes()[j] < strs[i - 1].as_bytes()[j] {
                    is_sorted = false;
                    break;
                }
            }

            if !is_sorted {
                count += 1;
            }
        }

        count
    }
}
