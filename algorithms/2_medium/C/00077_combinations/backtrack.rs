impl Solution {

    #[inline]
    fn binomial_coefficient(n: i32, k: i32) -> i32 {
        if k > n { return 0; }
        if k == 0 || k == n { return 1; }
        let mut res = 1_i64;
        for i in 1..=k {
            res = res * (n - k + i) as i64 / i as i64;
        }
        res as i32
    }

    fn backtrack(
        res: &mut Vec<Vec<i32>>,
        curr_vec: &mut Vec<i32>,
        start_val: i32,
        n: i32,
        k: i32
    ) {
        let curr_vec_len = curr_vec.len() as i32;
        if curr_vec_len == k {
            res.push(curr_vec.clone());
            return;
        }

        let end_val = n - (k - curr_vec_len) + 1;
        for i in start_val..= end_val {
            curr_vec.push(i);
            Self::backtrack(res, curr_vec, i + 1, n, k);
            curr_vec.pop();
        }
    }

    pub fn combine(n: i32, k: i32) -> Vec<Vec<i32>> {
        let mut res: Vec<Vec<i32>> = Vec::with_capacity(Self::binomial_coefficient(n, k) as usize);
        let mut curr_vec: Vec<i32> = Vec::with_capacity(k as usize);

        Self::backtrack(&mut res, &mut curr_vec, 1, n, k);

        res
    }
}
