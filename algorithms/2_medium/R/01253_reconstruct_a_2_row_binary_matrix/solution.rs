impl Solution {
    pub fn reconstruct_matrix(upper: i32, lower: i32, colsum: Vec<i32>) -> Vec<Vec<i32>> {
        let sum = colsum.iter().map(|x| *x).sum::<i32>();

        if sum != upper + lower {
            return Vec::default();
        }

        let count_twos = colsum.iter().filter(|x| **x == 2).count() as i32;

        if count_twos > upper || count_twos > lower {
            return Vec::default();
        }

        let cols = colsum.len();
        let rows = 2;
        let mut res = vec![vec![0_i32; cols]; rows];
        let mut remain_upper = upper - count_twos;
        let mut remian_lower = lower - count_twos;

        for j in 0..cols {
            match colsum[j] {
                1 => {
                    if remain_upper > 0 {
                        res[0][j] = 1;
                        remain_upper -= 1;
                    } else {
                        res[1][j] = 1;
                        remian_lower -= 1;
                    }
                },
                2 => {
                    res[0][j] = 1;
                    res[1][j] = 1;
                },
                _ => {},
            }
        }

        res
    }
}
