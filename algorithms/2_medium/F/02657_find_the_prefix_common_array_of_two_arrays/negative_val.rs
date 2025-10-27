impl Solution {
    pub fn find_the_prefix_common_array(mut a: Vec<i32>, b: Vec<i32>) -> Vec<i32> {

        let n = a.len();
        let mut res: Vec<i32> = Vec::with_capacity(n);
        let mut common = 0;

        for i in 0..n {
            let index_num_a = a[i].abs() as usize - 1;
            let index_num_b = b[i].abs() as usize - 1;

            if a[index_num_a] < 0 {
                common += 1;
            } else {
                a[index_num_a] *= -1;
            }

            if a[index_num_b] < 0 {
                common += 1;
            } else {
                a[index_num_b] *= -1;
            }

            res.push(common);
        }

        res
    }
}
