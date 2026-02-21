use std::collections::HashMap;

impl Solution {

    #[inline(always)]
    fn rev_digits(mut num: i32) -> i32 {
        let mut rev = 0;
        while num > 0 {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        rev
    }

    pub fn min_mirror_pair_distance(nums: Vec<i32>) -> i32 {
        let mut seen: HashMap<i32, usize> = HashMap::with_capacity(nums.len());
        let mut min_abs_diff: Option<usize> = None;

        for (i, num) in nums.into_iter().rev().enumerate() {
            let rev = Self::rev_digits(num);
            if let Some(val) = seen.get(&rev) {
                min_abs_diff = match min_abs_diff {
                    None => Some(i - *val),
                    Some(x) => Some((i - *val).min(x)),
                }
            }
            seen.entry(num).and_modify(|val| *val = i).or_insert(i);
        }

        match min_abs_diff {
            None => -1,
            Some(x) => x as i32,
        }
    }
}
