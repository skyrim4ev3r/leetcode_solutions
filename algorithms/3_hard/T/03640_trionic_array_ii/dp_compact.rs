impl Solution {
    pub fn max_sum_trionic(nums: Vec<i32>) -> i64 {
        let len = nums.len();
        let mut state: (Option<i64>, Option<i64>, Option<i64>) = (None, None, None);
        let mut res: Option<i64> = None;

        for i in 1..len {
            state = match nums[i].cmp(&nums[i - 1]) {
                std::cmp::Ordering::Less => {
                    (
                        None,
                        match (state.0, state.1) {
                            (None, Some(x)) | (Some(x), None) => Some(x + nums[i] as i64),
                            _ => None,
                        },
                        None,
                    )
                },
                std::cmp::Ordering::Equal => {
                    (None, None, None)
                },
                std::cmp::Ordering::Greater => {
                    (
                        match state.0 {
                            Some(x) => Some((nums[i - 1] as i64).max(x) + nums[i] as i64),
                            None => Some(nums[i - 1] as i64 + nums[i] as i64),
                        },
                        None,
                        match (state.1, state.2) {
                            (None, Some(x)) | (Some(x), None) => Some(x + nums[i] as i64),
                            _ => None,
                        }
                    )
                },
            };

            match state.2 {
                Some(x) => {
                    res = match res {
                        Some(some_res) => Some(some_res.max(x)),
                        _ => Some(x),
                    }
                },
                None => {},
            };
        };

        match res {
            Some(some_res) => some_res,
            None => unreachable!(), // It is guaranteed that at least one trionic subarray exists
        }
    }
}
