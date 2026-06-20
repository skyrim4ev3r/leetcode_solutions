const INF: i32 = 10_000_000;

impl Solution {
    pub fn min_side_jumps(obstacles: Vec<i32>) -> i32 {
        assert!(obstacles.len() > 1 && obstacles[0] == 0 && *obstacles.last().unwrap() == 0);
        let mut dp = [1, 0, 1];

        for obs in obstacles.into_iter().skip(1) {
            let obs_usize = obs as usize;

            if obs_usize > 0 {
                dp[obs_usize - 1] = INF;
            }

            let min = *dp.iter().min().unwrap();

            for i in 0..3 {
                if i + 1 != obs_usize {
                    dp[i] = dp[i].min(1 + min);
                }
            }
        }

        dp.into_iter().min().unwrap()
    }
}
