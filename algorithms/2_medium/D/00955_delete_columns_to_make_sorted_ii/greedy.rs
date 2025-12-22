impl Solution {
    pub fn min_deletion_size(strs: Vec<String>) -> i32 {
        let rows = strs.len();
        let cols = strs[0].len();
        let strs_bytes = strs.iter().map(|x| x.as_bytes()).collect::<Vec<_>>();
        let mut is_sorted = vec![false; rows];
        let mut count = 0_i32;

        for j in 0..cols {
            let mut should_delete = false;

            for i in 1..rows {
                if !is_sorted[i] {
                    if strs_bytes[i][j] < strs_bytes[i - 1][j] {
                        should_delete =true;
                        break;
                    }
                }
            }

            if should_delete {
                count += 1;
            } else {
                let mut are_all_sorted = true;

                for i in 1..rows {
                    is_sorted[i] |= (strs_bytes[i][j] > strs_bytes[i - 1][j]);
                    are_all_sorted &= is_sorted[i];
                }

                if are_all_sorted {
                    break;
                }
            }
        }

        count
    }
}
