impl Solution {
    pub fn last_visited_integers(nums: Vec<i32>) -> Vec<i32> {
        let mut seen: Vec<i32> = Vec::new();
        let mut consecutive_negative_ones = 0_usize;
        let mut res: Vec<i32> = Vec::new();

        for num in nums.iter() {
            if *num == -1 {
                consecutive_negative_ones += 1;
                let seen_len = seen.len();

                if consecutive_negative_ones > seen_len {
                    res.push(-1);
                } else {
                    res.push(seen[seen_len - consecutive_negative_ones]);
                }
            } else {
                seen.push(*num);
                consecutive_negative_ones = 0;
            }
        }

        res
    }
}
