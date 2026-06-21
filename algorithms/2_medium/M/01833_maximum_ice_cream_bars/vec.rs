impl Solution {
    pub fn max_ice_cream(costs: Vec<i32>, mut coins: i32) -> i32 {
        assert!(coins > 0);
        let (mut min, mut max) = (i32::MAX, i32::MIN);

        for &cost in costs.iter() {
            (min, max) = (min.min(cost), max.max(cost))
        }

        assert!(min > 0 && max > 0);
        let mut table = vec![0_i32; (max - min + 1) as usize];

        for cost in costs {
            table[(cost - min) as usize] += 1;
        }

        let mut cnt = 0_i32;
        for (i, freq) in table.into_iter().enumerate() {
            if freq > 0 {
                let val = i as i32 + min;
                let cnt_to_add = freq.min(coins / val);
                cnt += cnt_to_add;
                coins -= cnt_to_add * val;

                if (cnt_to_add < freq) {
                    break;
                }
            }
        }

        cnt
    }
}
