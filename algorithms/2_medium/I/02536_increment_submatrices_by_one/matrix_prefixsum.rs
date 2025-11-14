impl Solution {
    pub fn range_add_queries(n: i32, queries: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let n_usize = n as usize;
        let mut res: Vec<Vec<i32>> = vec![vec![0_i32; n_usize]; n_usize]; 

        for query in queries.into_iter() {
            let i1 = query[0] as usize;
            let j1 = query[1] as usize;
            let i2 = query[2] as usize;
            let j2 = query[3] as usize;

            for i in i1..=i2 {
                res[i][j1] += 1;

                if j2 + 1 < n_usize {
                    res[i][j2 + 1] -= 1;
                }
            }
        }

        for i in 0..n_usize {
            for j in 1..n_usize {
                res[i][j] += res[i][j - 1];
            }
        }

        res
    }
}
