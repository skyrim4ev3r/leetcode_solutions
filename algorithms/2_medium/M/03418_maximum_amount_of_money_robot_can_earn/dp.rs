impl Solution {
    pub fn maximum_amount(coins: Vec<Vec<i32>>) -> i32 {
        let rows = coins.len();
        let cols = coins[0].len();
        const skips: usize = 3;
        let mut costs = vec![vec![[i32::MIN; skips]; cols + 1]; rows + 1];
        costs[0][1].iter_mut().for_each(|v| *v = 0);

        for i in 0..rows {
            for j in 0..cols {
                for k in 0..skips {
                    let mut curr_cost = coins[i][j] + costs[i][j + 1][k].max(costs[i + 1][j][k]);

                    if k > 0 {
                        curr_cost = curr_cost.max(costs[i][j + 1][k - 1])
                                             .max(costs[i + 1][j][k - 1]);
                    }

                    costs[i + 1][j + 1][k] = curr_cost;
                } 
            }
        }

        costs[rows][cols].into_iter().max().unwrap()
    }
}
