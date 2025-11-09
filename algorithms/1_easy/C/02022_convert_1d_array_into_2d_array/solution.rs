impl Solution {
    pub fn construct2_d_array(original: Vec<i32>, m: i32, n: i32) -> Vec<Vec<i32>> {
        let rows = m as usize;
        let cols = n as usize;

        if rows * cols != original.len() {
            return Vec::new();
        }

        let mut res: Vec<Vec<i32>> = Vec::<Vec::<i32>>::with_capacity(rows);

        for i in 0..rows {
            res.push(original[i * cols..(i + 1) * cols].to_vec());
        }

        res
    }
}
