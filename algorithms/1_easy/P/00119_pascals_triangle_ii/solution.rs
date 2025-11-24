impl Solution {
    pub fn get_row(row_index: i32) -> Vec<i32> {
        let mut res = vec![1_i32];
        let len = (row_index + 1) as usize;

        while res.len() != len {
            let curr_len = res.len();
            let mut tmp: Vec<i32> = Vec::with_capacity(curr_len + 1);

            for i in 0..(curr_len + 1) {
                if i == 0 {
                    tmp.push(res[0]);
                } else if i == curr_len {
                    tmp.push(res[i - 1]);
                } else {
                    tmp.push(res[i] + res[i - 1]);
                }
            }

            res = tmp;
        }

        res
    }
}
