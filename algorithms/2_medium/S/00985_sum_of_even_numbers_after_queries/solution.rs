impl Solution {
    pub fn sum_even_after_queries(mut nums: Vec<i32>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let mut sum = nums.iter().map(|x| *x).filter(|num| (num & 1) == 0).sum::<i32>();
        let mut res = Vec::with_capacity(queries.len());

        for q in queries.into_iter() {
            let val = q[0];
            let index = q[1] as usize;

            if (nums[index] & 1) == 0 {
                sum -= nums[index];
            }

            nums[index] += val;

            if (nums[index] & 1) == 0 {
                sum += nums[index];
            }

            res.push(sum);
        }

        res
    }
}
