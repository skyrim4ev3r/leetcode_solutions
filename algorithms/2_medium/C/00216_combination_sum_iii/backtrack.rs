impl Solution {
    fn backtrack(res: &mut Vec<Vec<i32>>, curr_vec: &mut  Vec<i32>, k: usize, n: i32, curr_sum: i32, curr_num: i32) {

        if curr_vec.len() == k {
            if curr_sum == n {
                res.push(curr_vec.clone());
            }

            return;
        }

        for i in curr_num..10 {
            if i + curr_sum <= n {
                curr_vec.push(i);
                Self::backtrack(res, curr_vec, k, n, curr_sum + i, i + 1);
                curr_vec.pop();
            }
        }
    }

    pub fn combination_sum3(k: i32, n: i32) -> Vec<Vec<i32>> {

        let mut res: Vec<Vec<i32>> = Vec::new();
        let mut temp: Vec<i32> = Vec::with_capacity(k as usize);

        Self::backtrack(&mut res, &mut temp, k as usize, n, 0, 1);

        res
    }
}
