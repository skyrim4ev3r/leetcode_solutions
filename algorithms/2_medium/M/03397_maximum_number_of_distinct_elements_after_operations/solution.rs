impl Solution {
    pub fn max_distinct_elements(mut nums: Vec<i32>, k: i32) -> i32 {

        nums.sort_unstable();

        let mut last_distinct = i32::MIN;
        let mut count = 0_i32;

        for num in nums {
            let max_possible = num + k;

            if last_distinct < max_possible {
                last_distinct = (last_distinct + 1).max(num - k);
                count += 1;
            }
        }

        count
    }
}
