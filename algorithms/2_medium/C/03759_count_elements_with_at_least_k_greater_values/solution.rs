impl Solution {
    pub fn count_elements(mut nums: Vec<i32>, k: i32) -> i32 {
        let len = nums.len();

        if k == 0 {
            return len as i32;
        }

        nums.sort_unstable();
        let k_th_biggest = nums[len - k as usize];

        nums.binary_search_by(|x| match x.cmp(&k_th_biggest) {
                std::cmp::Ordering::Less => std::cmp::Ordering::Less,
                _ => std::cmp::Ordering::Greater
            })
            .unwrap_or_else(|x| x) as i32
    }
}
