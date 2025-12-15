impl Solution {
    pub fn num_rescue_boats(mut people: Vec<i32>, limit: i32) -> i32 {
        people.sort_unstable();
        let len = people.len();
        let mut count = 0_i32;
        let mut left = 0_usize;
        let mut right = len - 1;

        while right < len && left <= right {
            if left < right && people[left] + people[right] <= limit {
                left += 1;
            }

            count += 1;
            right -= 1;
        }

        count
    }
}
