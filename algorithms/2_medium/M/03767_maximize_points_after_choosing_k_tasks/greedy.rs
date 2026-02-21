impl Solution {
    pub fn max_points(technique1: Vec<i32>, technique2: Vec<i32>, mut k: i32) -> i64 {
        let sum_tech2 = technique2.iter().map(|x| *x as i64).sum::<i64>();
        let mut diff: Vec<_> = technique1.into_iter().zip(technique2.into_iter()).map(|(t1, t2)| t1 - t2).collect();
        diff.sort_unstable_by(|a, b| b.cmp(&a));
        let forced_to_pick = diff[0..(k as usize)].iter().map(|x| *x as i64).sum::<i64>();
        let pick_if_good = diff[(k as usize)..].iter().filter(|&&x| x > 0).map(|x| *x as i64).sum::<i64>();

        sum_tech2 + forced_to_pick + pick_if_good
    }
}
