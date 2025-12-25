impl Solution {
    pub fn count_pairs(mut nums: Vec<i32>, target: i32) -> i32 {
        nums.sort_unstable();
        let mut count = 0_i32;
        let len = nums.len();

        for i in 0..len {
            let other_max = target - nums[i];
            let pos = nums.binary_search_by(|x| match x.cmp(&other_max) {
                std::cmp::Ordering::Greater => std::cmp::Ordering::Greater,
                std::cmp::Ordering::Equal => std::cmp::Ordering::Greater,
                std::cmp::Ordering::Less => std::cmp::Ordering::Less,
            }).unwrap_or_else(|x| x);

            if pos > i {
                count += (pos - i - 1) as i32;
            }
        }

        count
    }
}
