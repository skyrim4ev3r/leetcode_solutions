use std::cmp::Ordering;

impl Solution {
    pub fn largest_number(nums: Vec<i32>) -> String {
        let mut nums_str = nums.into_iter().map(|x| x.to_string()).collect::<Vec<_>>();

        nums_str.sort_unstable_by(|a, b| {
            let a_len = a.len();
            let b_len = b.len();
            let a_bytes = a.as_bytes();
            let b_bytes = b.as_bytes();
            let total = a_len + b_len;

            for i in 0..total {
                let a_index = i % a_len;
                let b_index = i % b_len;

                if a_bytes[a_index] != b_bytes[b_index] {
                    return b_bytes[b_index].cmp(&a_bytes[a_index]);
                }
            }

            Ordering::Equal
        });

        if nums_str[0] == "0" {
            return "0".to_string();
        }

        nums_str.join("")
    }
}
