impl Solution {
    #[inline(always)]
    fn max_taxi_earnings_dense(n: i32, rides: Vec<Vec<i32>>) -> i64 {
        let mut best_ending_at = vec![0_i64; n as usize + 1];
        let mut adj: Vec<Vec<(i32, i32)>> = vec![Vec::default(); n as usize + 1];

        for r in rides {
            adj[r[0] as usize].push((r[1], r[2]));
        }

        let mut global_best_so_far = 0_i64;
        for i in 1..=n {
            global_best_so_far = global_best_so_far.max(best_ending_at[i as usize]);

            for &(end, tip) in adj[i as usize].iter() {
                let ride_earnings = (end - i) + tip;
                let new_profit = global_best_so_far + ride_earnings as i64;
                best_ending_at[end as usize] = best_ending_at[end as usize].max(new_profit);
            }
        }

        global_best_so_far
    }

    #[inline(always)]
    fn max_taxi_earnings_sparse(n: i32, rides: Vec<Vec<i32>>) -> i64 {
        let mut best_ending_at = vec![0_i64; n as usize + 1];
        let mut adj: Vec<(i32, i32, i32)> = Vec::with_capacity(rides.len());

        for r in rides {
            adj.push((r[0], r[1], r[2]));
        }

        adj.sort_unstable_by_key(|x| x.0);

        let mut global_best_so_far = 0_i64;
        let mut adj_idx = 0;
        for i in 1..=n {
            global_best_so_far = global_best_so_far.max(best_ending_at[i as usize]);

            while let Some(&(start, end, tip)) = adj.get(adj_idx) && start == i {
                adj_idx += 1;
                let ride_earnings = (end - i) + tip;
                let new_profit = global_best_so_far + ride_earnings as i64;
                best_ending_at[end as usize] = best_ending_at[end as usize].max(new_profit);
            }
        }

        global_best_so_far
    }

    pub fn max_taxi_earnings(n: i32, rides: Vec<Vec<i32>>) -> i64 {
        assert!(n > 0);

        if rides.len() > 6 * n as usize {
            Self::max_taxi_earnings_dense(n, rides)
        } else {
            Self::max_taxi_earnings_sparse(n, rides)
        }
    }
}
