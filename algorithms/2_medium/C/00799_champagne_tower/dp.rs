/*
    Each glass with index j has 2 parent glasses: j and j - 1.

    Each glass receives half of the amount that its parents throw.

    using 2 arrays:
        -One array tracks the fill percentage of the glasses.
        -Another array tracks how much they throw.

    Fill the first glass parent with 2 * poured, so the first glass gets half of it.
        throw_info[0] = 2.0 * poured
*/

impl Solution {
    pub fn champagne_tower(poured: i32, query_row: i32, query_glass: i32) -> f64 {
        let query_row = query_row as usize;
        let mut fill_info = vec![0_f64; query_row + 1];
        let mut throw_info = vec![0_f64; query_row + 1];
        throw_info[0] = (2 * poured) as f64;

        for i in 0..(query_row + 1) {
            for j in (0..(i + 1)).rev() {
                let amount = (throw_info[j] / 2_f64) + if j > 0 { throw_info[j - 1] / 2_f64 } else { 0_f64 } ;
                fill_info[j] =  amount.min(1_f64);
                throw_info[j] = (amount - 1_f64).max(0_f64);
            }
        }

        fill_info[query_glass as usize]
    }
}
