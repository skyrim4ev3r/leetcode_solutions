impl Solution {
    pub fn maximum_count(nums: Vec<i32>) -> i32 {
        let lower_bound_zero = nums.binary_search_by(|num| match num.cmp(&0) {
            std::cmp::Ordering::Greater => std::cmp::Ordering::Greater,
            std::cmp::Ordering::Equal => std::cmp::Ordering::Greater,
            std::cmp::Ordering::Less => std::cmp::Ordering::Less,
        }).unwrap_or_else(|x| x);

        let upper_bound_zero = nums.binary_search_by(|num| match num.cmp(&0) {
            std::cmp::Ordering::Greater => std::cmp::Ordering::Greater,
            std::cmp::Ordering::Equal => std::cmp::Ordering::Less,
            std::cmp::Ordering::Less => std::cmp::Ordering::Less,
        }).unwrap_or_else(|x| x);

        let len = nums.len();

        (len - upper_bound_zero).max(lower_bound_zero) as i32
    }
}
