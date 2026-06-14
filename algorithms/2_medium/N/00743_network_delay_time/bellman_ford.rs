impl Solution {
    pub fn network_delay_time(times: Vec<Vec<i32>>, n: i32, k: i32) -> i32 {
        debug_assert!(times.len() > 0 && n > 0 && k > 0 && k <= n);

        let mut dist = vec![i32::MAX; n as usize + 1];
        dist[k as usize] = 0;

        for _ in 0..n {
            let mut is_updated = false;

            for t in times.iter() {
                debug_assert!(t.len() == 3);
                let (u, v, w) = (t[0], t[1], t[2]);
                debug_assert!(u > 0 && v > 0 && u <= n && v <= n && w >= 0);

                if dist[u as usize] != i32::MAX && dist[u as usize] + w < dist[v as usize] {
                    dist[v as usize] = dist[u as usize] + w;
                    is_updated = true;
                }
            }

            if !is_updated { 
                break;
            }
        }

        let max_dist = *dist[1..].into_iter().max().unwrap();

        if max_dist == i32::MAX { -1 } else { max_dist }
    }
}
