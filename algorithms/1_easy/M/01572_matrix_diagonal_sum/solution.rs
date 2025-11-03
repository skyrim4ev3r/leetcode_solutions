impl Solution {
    pub fn diagonal_sum(mat: Vec<Vec<i32>>) -> i32 {

        let n = mat.len();
        let mut sum = 0_i32;

        for i in 0..n {
            sum += mat[i][i];
            sum += mat[n - 1 -i][i];
        }

        if (n & 1) == 1 {
            let center = n / 2;
            sum -= mat[center][center];
        }

        sum
    }
}
