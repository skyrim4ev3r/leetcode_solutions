impl Solution {

    #[inline(always)]
    fn calc_cost(arr: &[i32], brr: &[i32]) -> i64 {
        arr.iter()
            .zip(brr.iter())
            .map(|(a, b)| (*a as i64 - *b as i64).abs())
            .sum::<i64>()
    }

    pub fn min_cost(mut arr: Vec<i32>, mut brr: Vec<i32>, k: i64) -> i64 {
        let by_default_cost = Self::calc_cost(&arr, &brr);
        arr.sort_unstable();
        brr.sort_unstable();
        let by_sort_cost = k + Self::calc_cost(&arr, &brr);

        by_default_cost.min(by_sort_cost)
    }
}
