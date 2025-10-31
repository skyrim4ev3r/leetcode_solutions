impl Solution {
    pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {

        let rows = num_rows as usize;
        let mut res: Vec<Vec<i32>> = Vec::with_capacity(rows);

        res.push(vec![1_i32]);

        for i in 1..rows {
            let mut tmp: Vec<i32> = Vec::with_capacity(i + 1);

            for j in 0..=i {
                let mut curr_val = 0_i32;

                if j < i {
                    curr_val += res[i - 1][j];
                }

                if j > 0 {
                    curr_val += res[i - 1][j - 1];
                } 

                tmp.push(curr_val);
            }

            res.push(tmp);
        }

        res
    }
}
