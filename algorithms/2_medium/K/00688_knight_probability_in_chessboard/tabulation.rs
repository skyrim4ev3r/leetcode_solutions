impl Solution {
    const DIRECTIONS: [(isize, isize); 8] = [
        (-1, 2), (-2, 1), (-2, -1), (-1, -2),
        (1, 2), (2, 1), (2, -1), (1, -2),
    ];

    pub fn knight_probability(n: i32, k: i32, row: i32, col: i32) -> f64 {
        assert!(row >= 0 && col >= 0 && row < n && col < n && k >= 0);
        let (n, row, col) = (n as isize, row as isize, col as isize);
        if k == 0 { return 1_f64; };
        let mut dp: Vec<f64> = Vec::with_capacity((n * n * 2) as usize);
        unsafe { dp.set_len((n * n * 2) as usize); }
        let (mut curr, mut next) = dp.split_at_mut((n * n) as usize);
        curr.iter_mut().for_each(|x| *x = 0_f64);
        next.iter_mut().for_each(|x| *x = 1_f64);

        for i in 1..=k  {
            for r in 0..n {
                for c in 0..n {
                    let curr_memo_idx = r * n + c;
                    let mut prob = 0_f64;
                    for (dx, dy) in Self::DIRECTIONS {
                        let (nr, nc) = (r + dx, c + dy);
                        if nr >= 0 && nc >= 0 && nr < n && nc <n {
                            let next_memo_idx = nr * n + nc;
                            prob += next[next_memo_idx as usize];
                        }
                    }
                    curr[curr_memo_idx as usize] = prob / Self::DIRECTIONS.len() as f64;
                }
            }
            (curr, next) = (next, curr);
        }

        next[(row * n + col) as usize]
    }
}
