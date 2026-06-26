impl Solution {
    pub fn max_profit_assignment(difficulty: Vec<i32>, profit: Vec<i32>, mut worker: Vec<i32>) -> i32 {
        assert!(difficulty.len() == profit.len());
        let mut jobs: Vec<(i32, i32)> = difficulty.into_iter().zip(profit.into_iter()).collect();
        jobs.sort_unstable();
        worker.sort_unstable();

        let mut res = 0_i32;
        let mut max_profit = 0_i32;
        let mut jobs_idx = 0;
        let jobs_len = jobs.len();

        for w in worker {
            while jobs_idx < jobs_len && jobs[jobs_idx].0 <= w {
                max_profit = max_profit.max(jobs[jobs_idx].1);
                jobs_idx += 1;
            }

            res += max_profit;
        }

        res
    }
}
