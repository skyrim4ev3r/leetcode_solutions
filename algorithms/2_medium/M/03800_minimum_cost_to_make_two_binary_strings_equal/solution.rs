impl Solution {
    pub fn minimum_cost(s: String, t: String, flip_cost: i32, swap_cost: i32, cross_cost: i32) -> i64 {
        let (s_bytes, t_bytes) = (s.as_bytes(), t.as_bytes());
        let (flip_cost, swap_cost, cross_cost) = (flip_cost as i64, swap_cost as i64, cross_cost as i64);
        let len = s_bytes.len();
        let mut xy = 0_i64;
        let mut yx = 0_i64;

        for i in 0..len {
            if s_bytes[i] != t_bytes[i] {
                if s_bytes[i] == b'1' {
                    xy += 1;
                } else {
                    yx += 1;
                }
            }
        }

        let unequal_pairs = xy + yx;
        let possible_direct_swaps = xy.min(yx);
        let impossible_direct_swaps = (xy - yx).abs();
        let possible_cross = impossible_direct_swaps / 2;
        let force_flips = (impossible_direct_swaps & 1);

        let all_flips_cost = unequal_pairs * flip_cost;

        let all_flips_swap_cost = impossible_direct_swaps * flip_cost +
                                  possible_direct_swaps * swap_cost;

        let flips_swap_cross_cost = force_flips * flip_cost +
                                    possible_direct_swaps * swap_cost +
                                    possible_cross * (cross_cost + swap_cost);

        all_flips_cost
        .min(all_flips_swap_cost)
        .min(flips_swap_cross_cost)
    }
}
